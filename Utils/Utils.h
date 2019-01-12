#ifndef SPOCK_UTILS
#define SPOCK_UTILS

#include <iostream>
#include <list>

void PrintList(std::list<int> &data);
void PrintListSize(std::list<std::list<int> > &data, int number);

// void PrintList(std::list<int> &data)
// {
//     for (auto iter = data.begin(); iter != data.end(); ++iter)
//     {
//         std::cout << *iter << " ";
//     }
//     std::cout << std::endl;
// }

#endif