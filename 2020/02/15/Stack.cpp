#include <iostream>
using namespace std;
struct Node
{
  char data;
  Node* next=NULL;
};
ostream& operator<<(ostream& out, const Node& a) {
	return out << a.data << endl;
};

struct Stack
{
  Node* head = NULL;
  Stack(char x)
  {
      head = new Node;
      head->data=x;
  }
  void push(char a)
  {
      if(head==NULL)
      {
          head=new Node;
          head->data=a;
          return;
      }
      
      Node* temp = new Node;
      temp->data=a;
      temp->next = head;
      head=temp;
  }
  int pop()
  {
      Node* temp = head;
      head=head->next;
      char a = temp->data;
      delete temp;
      return a;
  }
  ~Stack()
  {
      while(head!=NULL)
      {
          Node* temp = head;
          head = head->next;
          delete temp;
      }
  }
  void multipop(int k)
  {
      while((head!=NULL)&&(k!=0))
      {
          Node* temp =head;
          head=head->next;
          delete temp;
          k--;
      }
  }
};

int main()
{
    int n; //number of brackets
    char x; //input char
    cin >> n;
    cin >> x; //first char
    Stack a(x);
    for(int i = 1; i<n; i++){
        cin >> x;
        a.push(x);
    }
    
    if(char(a.pop())=='('){;
        cout << "FALSE";
        return 0;
    }
    int openbrackets = 1;
    int closebrackets = 0;
    for(int i = 1;i < n; i++)
    {
        if(char(a.pop())=='(')
        {
            closebrackets++;
        }else{
            openbrackets++;
        }
        
       if(openbrackets < closebrackets)
        {
            cout << "FALSE";
            return 0;
        }
    } 
    
    if(openbrackets==closebrackets)
        {
            cout << "TRUE";
        }else{
            cout << "FALSE";
        }
        
   return 0;
}
