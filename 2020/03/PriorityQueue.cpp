//Чем меньше приоритет элемента, тем раньше он будет извлечён. 

#include <iostream>
using namespace std;

struct Node
{
    int priority;
    Node* next;
};


struct PriorityQueue
{
    Node* head=NULL;
    Node* tail=NULL;
    Node* iterator;
    PriorityQueue(int x)
    {
        head = new Node;
        tail = new Node;
        head -> priority = x;
        tail -> priority = x;
    }
    void push(int x)
    {
        if(head == NULL)
        {
            head = new Node;
            tail = new Node;
            head -> priority = x;
            tail -> priority = x;
            return;
        }
        Node* temp = new Node;
        temp -> priority = x;
      
        if(x > tail -> priority)
        {
            temp -> next = tail;
            tail = temp;
        }
        else
        {
            Node* prev = new Node;
            iterator=tail;
            while(x < iterator -> priority)
            {
                if(iterator -> next == NULL)
                {
                    iterator -> next = temp;
                    head = temp;
                    return;
                }
                prev = iterator;
                iterator = iterator -> next;
            }
            prev -> next = temp;
            temp -> next = iterator;
        }
    }
     
    int pop()
    {
        Node* prev1 = new Node;
        iterator = tail;
        while(iterator -> next != NULL)
        {
            prev1 = iterator;
            iterator = iterator -> next;
        }
        Node* temp = iterator;
        int a = iterator -> priority;
        prev1 -> next = NULL;
        delete temp;
        return a;
    }
};

int main()
{
    int numberOfElements,firstPriority;
    cout << "Enter numberOfElements:";
    cin >> numberOfElements;
    cout << "Enter firstPriority:";
    cin >> firstPriority;
    PriorityQueue a(firstPriority);
    
    for(int i = 1; i < numberOfElements;i++)
    {
        cin >> firstPriority;
        a.push(firstPriority);
    }
    cout << "===============" << endl;
    
    for(int i = 0; i < numberOfElements;i++)
    {
        cout << a.pop() << endl;
    }
    return 0;
}
        cin >> priority;
        a.push(priority);        
    }
    for(int i = 0; i<numberOfElements;i++)
    {
        a.pop();    
    }
    return 0;
}
