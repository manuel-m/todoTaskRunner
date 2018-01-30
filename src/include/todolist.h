#ifndef _TODOLIST
#define _TODOLIST

#include <iostream>
#include <map>
#include <mutex>
#include <string>
#include <thread>

#include "task.h"

class TodoList
{
private:
  TodoList(const TodoList &TodoList); // no copy

  std::mutex _mutex;

  bool _quit;
  std::map<std::string, Task> _tasksMap;

  // commands
  void _doCreate(std::string &command_);
  void _doDelete(std::string &command_);
  void _doEdit(std::string &command_);
  void _doList();
  void _doQuit();

  static void _tasksRunner(TodoList &); // thread

public:
  TodoList() : _quit(false)
  {
  }

  // TODO: const cast
  std::map<std::string, Task> &getTasksMap() { return _tasksMap; };

  void edit();
  bool shallContinue() { return _quit == false; };

  void lock() { _mutex.lock(); };
  void unlock() { _mutex.unlock(); };

  std::thread launchTaskRunner();

  void processCommand(std::string &command_);

  static void help();
};

#endif /* _TODOLIST */