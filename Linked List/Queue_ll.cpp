#include <iostream>
#define MAX 10
using namespace std;

class Node{
public:
    int info;
    Node *next;
    
};

class Queue{
private:
    Node *HEAD;
    Node *TAIL;
    int count=0;
public:
    Queue();
    ~Queue();

    bool isEmpty();             
    void enqueue( int  element);    
     int dequeue();             
     int peekFront();          
     int peekRear();            
    void traverse();            
};





Queue :: Queue(){
    HEAD = NULL;
    TAIL = NULL;

}

Queue :: ~Queue(){}

bool Queue :: isEmpty(){
    return (HEAD == NULL);
}

void Queue :: enqueue( int  element){
    if (count == MAX){
        cout << "Queue overflow!" << endl;
    }
    else{
        Node *newNode = new Node();
        newNode -> info =  element;
        newNode -> next = NULL;
        if(isEmpty()){
            TAIL = newNode;    
            HEAD = TAIL;
        }
        else{
            TAIL -> next = newNode;
            TAIL = newNode;
        }
        count++;
    }
}

 int Queue :: dequeue(){
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
        return '-';
    }
    else{
        Node *toDelete;
         int value;
        toDelete = HEAD;
        value = toDelete -> info;
        HEAD = toDelete -> next;
        delete toDelete;
        count--;
        return value;
    }

}

 int Queue :: peekFront(){
    if (isEmpty()){
        cout << "Queue Underflow!" <<endl;
        return '-';
    }
    else{
        return (HEAD -> info);
    }
}

 int Queue :: peekRear(){
    if (isEmpty()){
        cout << "Queue Overflow!" << endl;
        return '-';
    }
    else{
        return (TAIL -> info);
    }
}

void Queue :: traverse(){
    Node *temp = HEAD;
    while (temp != NULL){
        cout << temp -> info <<endl;
        temp = temp -> next;
    }
}


int main(){
    Queue Q;
    cout << Q.isEmpty() << endl; //Returns 1 if true 
     
    Q.dequeue();
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    Q.enqueue(6);
    Q.traverse();
     
    cout << Q.peekFront() << endl;  //1
    cout << Q.peekRear() << endl;   //6
     
    Q.dequeue();
    Q.dequeue();
    Q.enqueue(7);
    Q.enqueue(8);
    Q.enqueue(9);
    Q.traverse();
     
    
    return 0;
}