#include "todolist.h"

void TodoList::_tasksRunner(TodoList &tdl_)
{
    while (tdl_.shallContinue() == true)
    {
        time_t now;
        tdl_.lock();
        time(&now);
        {
            std::map<std::string, Task>::iterator it = tdl_.getTasksMap().begin();

            while (it != tdl_.getTasksMap().end())
            {
                // start running task
                if (now > it->second.start_ts && it->second.running == false)
                {
                    std::cout << ">>  start:" << it->first << std::endl;
                    it->second.running = true;
                }

                // stop running task
                if (now < it->second.start_ts && it->second.running == true)
                {
                    std::cout << ">>  stop:" << it->first << std::endl;
                    it->second.running = false;
                }

                it++;
            }
        }
        tdl_.unlock();

        // sleep 1 sec
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

std::thread TodoList::launchTaskRunner()
{
    std::thread _tasksRunnerThread(
        _tasksRunner, std::ref(*this)

    );
    return _tasksRunnerThread;
}
