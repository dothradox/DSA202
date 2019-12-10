#include<iostream>
using namespace std;

class node
{
 public:
    int data;
    node* next;
};

class Stack
{
public:
    Stack(int max)
    {
        HEAD = NULL;
        maxnum = max;
        count=0;
    }

    void push(int element)
    {
        if(count == maxnum)
                cout<<"Stack overflow";
        else
        {
            node *newNode = new node;
            if(HEAD == NULL)
            {
                newNode->data = element;
                newNode->next = NULL;
                HEAD = newNode;
                count++;
            }
            else
            {
                newNode->data = element;
                newNode->next = HEAD;
                HEAD = newNode;
                count++;
            }
        }
    }

    void pop()
    {
        if(isEmpty())
                cout<< "Stack underflow";
        else
        {
            node * old = HEAD;
            HEAD = HEAD->next;
            count--;
            delete(old);
        }
    }
    void traverse()
    {
        node *temp;
        temp = HEAD;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
    int top(){
        if(isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            return (HEAD -> info);
        }
    }
    bool isEmpty()
    {
        return(HEAD==NULL)
    }
private:
    node *HEAD;
    int count; //HEAD
    int maxnum;
    int stackData;
};

int main(int argc, char** argv) {
    Stack *obj = new Stack(5); // stack of size 5 is created 
    obj->push(10);
    obj->push(5);
    obj->push(3);
    obj->push(9);
    obj->push(4);
    obj->push(2);

    obj->pop();
    cout<<"new stack\n";
    obj->traverse();

    return 0;
}