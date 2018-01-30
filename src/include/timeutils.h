#ifndef _TIMESUTILS
#define _TIMESUTILS

#include <iomanip>
#include "split.h"

long int date2Ts(std::string &date_, std::string &time_)
{
    std::string::size_type sz;
    std::tm t_ = {};

    std::vector<std::string> _date, _time;

    split(date_, _date, '-');
    t_.tm_year = std::stoi(_date[0], &sz) - 1900;
    t_.tm_mon = std::stoi(_date[1], &sz) - 1;
    t_.tm_mday = std::stoi(_date[2], &sz);

    split(time_, _time, ':');
    t_.tm_hour = std::stoi(_time[0], &sz);
    t_.tm_min = std::stoi(_time[1], &sz);

    return mktime(&t_);
}

void ts2Date(const time_t &_time, std::string &s_)
{
    struct tm ts;
    char buf[80];

    // Format time, "yyyy-mm-dd hh:mm"
    ts = *localtime(&_time);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M", &ts);
    // printf("%s\n", buf);
    s_ = buf;
}

#endif /* _TIMESUTILS */