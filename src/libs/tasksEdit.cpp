#include <string.h>

#include "split.h"
#include "timeutils.h"
#include "todolist.h"

void TodoList::_doCreate(std::string &command_)
{
    // create t1 1 from 2018-01-30 08:00 to 2018-01-30 12:00
    std::string::size_type sz;
    std::vector<std::string> _f;
    split(command_, _f, ' ');

    lock();
    {
        std::string _name = _f[1];
        int _priority = std::stoi(_f[2], &sz);
        long int _start = date2Ts(_f[4], _f[5]);
        long int _end = date2Ts(_f[7], _f[8]);

        _tasksMap[_name] = Task(_priority, _start, _end);
        std::cout
            << ">>  added Task[" << _name << "] "
            << "(" << _priority << "," << _start << "," << _end << ")" << std::endl;
    }
    unlock();
}

void TodoList::_doDelete(std::string &command_)
{
    std::vector<std::string> _f;
    split(command_, _f, ' ');
    std::string _name = _f[1];
    lock();
    {
        std::map<std::string, Task>::iterator it = _tasksMap.find(_name);
        if (it != _tasksMap.end())
        {
            _tasksMap.erase(it);
            std::cout << _name << " deleted" << std::endl;
        }
        else
        {
            std::cout << _name << " not found" << std::endl;
        }
    }

    unlock();
}

void TodoList::_doEdit(std::string &command_)
{
    _doCreate(command_);
}

void TodoList::_doList()
{
    lock();
    {
        if (_tasksMap.size() == 0)
        {
            std::cout << ">>  No task to display" << std::endl;
        }
        else
        {
            std::map<std::string, Task>::iterator it = _tasksMap.begin();

            while (it != _tasksMap.end())
            {
                std::string _start;
                std::string _end;
                ts2Date(it->second.start_ts, _start);
                ts2Date(it->second.end_ts, _end);

                std::cout << ">>  " << it->first << " :: "
                          << it->second.priority << " "
                          << it->second.start_ts << "(" << _start << ") "
                          << it->second.end_ts << "(" << _end << ") "
                          << std::endl;
                it++;
            }
        }
    }
    unlock();
}

void TodoList::_doQuit()
{
    lock();
    _quit = true;
    unlock();
}

void TodoList::edit()
{
    std::string _command;
    while (shallContinue() == true)
    {
        std::cout << "command? ";
        std::getline(std::cin, _command);
        processCommand(_command);
    }
}

void TodoList::processCommand(std::string &command_)
{
    // quit
    if (command_ == std::string("quit"))
    {
        _doQuit();
        return;
    }

    // list
    if (command_ == std::string("list"))
    {
        _doList();
        return;
    }

    // create
    if (strncmp(command_.c_str(), "create", 6) == 0)
    {
        _doCreate(command_);
        return;
    }

    // edit
    if (strncmp(command_.c_str(), "edit", 4) == 0)
    {
        _doEdit(command_);
        return;
    }

    // delete
    if (strncmp(command_.c_str(), "delete", 6) == 0)
    {

        _doDelete(command_);
        return;
    }
}

void TodoList::help()
{
    std::cout << "TODOLIST " << std::endl;
    std::cout << "Available commands:" << std::endl;
    std::cout << std::endl;
    std::cout << "> list" << std::endl;
    std::cout << "> quit" << std::endl;
    std::cout << "> create task_name priority from YYYY-MM-DD hh:mm to YYYY-MM-DD hh:mm" << std::endl;
    std::cout << "      ex: create t1 1 from 2018-01-30 08:00 to 2018-01-30 12:00" << std::endl;
    std::cout << "> edit task_name priority from YYYY-MM-DD hh:mm to YYYY-MM-DD hh:mm" << std::endl;
    std::cout << "      ex: edit t1 2 from 2018-01-30 10:00 to 2018-01-30 10:00" << std::endl;
    std::cout << "> delete task_name" << std::endl;
    std::cout << "      ex: delete t1" << std::endl;

    std::cout << std::endl;
}