#include <iostream>
#include <algorithm>
#include <list>
#include <forward_list>
using namespace std;

int main()
{
    forward_list<int> single_link = {1,2,3,4,5};
    list<int> double_link = {6,7,8,9,10};
    cout << "single_link" << endl;
    for(auto i : single_link)
    {
        cout << i << endl;
    }
    single_link.push_front(0);
    cout << "single_link after push_front(0)" << endl;
    for(auto i : single_link)
    {
        cout << i << endl;
    }
    single_link.pop_front();
    cout << "single_link after pop_front(0)" << endl;
    for(auto i : single_link)
    {
        cout << i << endl;
    }
    single_link.insert_after(single_link.begin()++,2,10);
    cout << "single_link after insert_after(single_link.begin()++,2,2)" << endl;
     for(auto i : single_link)
    {
        cout << i << endl;
    }
    double_link.emplace_back(1);
    for(auto i : double_link)
    {
        cout << i << endl;
    }
    return 0;
}
