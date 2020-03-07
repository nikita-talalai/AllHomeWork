#include <iostream>
using namespace std;

//priority = 1 > priority = 2

struct Node
{
    int priority;
    Node* next = NULL;
};

struct PriorityQueue
{
    Node* head = NULL;
    PriorityQueue(int priority)
    {
        head = new Node;
        head -> priority = priority;
    }
    ~PriorityQueue()
    {
        while(head!=NULL)
        {
          Node* temp = head;
          head = head-> next;
          delete temp;
        }
    }
    void push(int priority)
    {
        if(head==NULL)
        {
            head = new Node;
            head -> priority = priority;
            return;
        }
        
        Node* temp = new Node;
        temp -> priority = priority;
            temp->next = head;
            head=temp;
            return;
    }
    int pop()
    {
      Node* temp = head;
      head=head->next;
      int a = temp->priority;
      delete temp;
      return a;
       
    }
};

int main()
{
    int priority, numberOfElements;
    
    cin >> numberOfElements >> priority;
    PriorityQueue a(priority);
    for(int i = 1; i < numberOfElements;i++)
    {
        cin >> priority;
        a.push(priority);        
    }
    for(int i = 0; i<numberOfElements;i++)
    {
        a.pop();    
    }
    return 0;
}
