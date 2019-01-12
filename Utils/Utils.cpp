#include <iostream>
#include <list>
#include "Utils.h"

void PrintList(std::list<int> &data)
{
    for (auto iter = data.begin(); iter != data.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

void PrintListSize(std::list<std::list<int> > &data, int number)
{
    int index = 0;
    for (auto iter = data.begin(); iter != data.end(); ++iter)
    {
        if (index == number)
        {
            break;
        }

        std::cout << (*iter).size() << " ";
        ++index;
    }
    std::cout << std::endl;
}