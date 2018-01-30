#include <iostream>
#include <fstream>
#include <cassert>

#include "task.h"

void t0();

int main(int argc, char **argv)
{
    t0();
    return 0;
}

void t0()
{
    Task _task;
    assert(_task.priority == 0);
    assert(_task.start_ts == 0);
    assert(_task.end_ts == 0);
}