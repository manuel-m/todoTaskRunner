#ifndef _SPLIT
#define _SPLIT

#include <iostream>
#include <vector>
#include <sstream>

void split(std::string &command_, std::vector<std::string> &strs_, char delimitor_)
{
    strs_.clear();

    std::istringstream iss(command_);
    std::string s;
    while (getline(iss, s, delimitor_))
    {
        strs_.push_back(s);
    }
}

#endif /* _SPLIT */