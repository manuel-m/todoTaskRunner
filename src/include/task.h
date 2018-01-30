#ifndef _TASK_T
#define _TASK_T

class Task
{
public:
  Task(int prio_ = 0, long int start_ = 0, long int end_ = 0)
      : priority(prio_),
        start_ts(start_),
        end_ts(end_)
  {
  }
  Task(const Task &task_) : priority(task_.priority),
                            running(false),
                            start_ts(task_.start_ts),
                            end_ts(task_.end_ts) {}

  int priority;
  bool running;
  long int start_ts;
  long int end_ts;
};

#endif /* _TASK_T */