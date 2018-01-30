
#include "todolist.h"

int main()
{
    TodoList _tdl;

    // tasks runner is wrapped in a dedicated thread
    std::thread _tasksRunnerThread = _tdl.launchTaskRunner();

    TodoList::help();
    _tdl.edit();

    _tasksRunnerThread.join();
    return 0;
}
