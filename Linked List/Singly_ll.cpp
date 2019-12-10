#include <iostream>
using namespace std;

class Node{
public:
  int info;
  Node *next;
};

class List{
private:
  Node *HEAD;
  Node *TAIL;
public:
  List();
  ~List();

  bool isEmpty();
  void addtoHead(int element);
  void addtoTail(int element);
  void add(int element, Node* &predecessor);


  void removefromHead();
  void remove(int element);

  bool search(int element);
  void traverse();
  bool retrieve(int element, Node* &outputPtr);
};
List :: List(){
  HEAD = NULL;
  TAIL = NULL;
}

List :: ~List(){}

bool List :: isEmpty(){
  if (HEAD == NULL)
    return true;
  else
    return false;
}

void List :: addtoHead(int element){
  Node* newNode = new Node();
  newNode -> info = element;
  newNode -> next = HEAD;
  HEAD = newNode;
  if (TAIL == NULL)
    TAIL = HEAD;

}

void List :: addtoTail(int element){
  Node* newNode = new Node();
  newNode -> info = element;
  newNode -> next = NULL;
  TAIL -> next = newNode;
  TAIL = newNode;
}

void List :: add(int element, Node* &predecessor){
  Node* newNode = new Node();
  newNode -> info = element;
  newNode -> next = predecessor -> next;
  predecessor -> next = newNode;
}

void List :: removefromHead(){
  Node* toDelete;
  toDelete = HEAD;
  HEAD = toDelete -> next;
  delete (toDelete);
}

void List :: remove(int element){
  Node* temp;
  Node *prev;
  if(isEmpty()){
    cout << "Underflow" << endl;
  }
  else {
    if(HEAD -> info == element)
      {
      removefromHead();
      if(HEAD == NULL)
        TAIL = NULL;
      }
    else
    {
      temp = HEAD -> next;
      prev = HEAD;
      while (temp != NULL)
      {
        if(temp -> info == element)
        {
          prev -> next = temp -> next;
          delete temp;
          if(prev -> next == NULL)
            TAIL = prev;
          break;
        }
        else
        {
          prev = prev -> next;
          temp = temp -> next;
        }
      }
    }
   }
}

bool List :: search(int element){
  Node* temp;
  temp = HEAD;
  while(temp != NULL)
  {
    if( temp -> info == element)
      return true;
    else
      temp = temp -> next;
  }
  return false;
}

void List :: traverse(){
  Node* temp = HEAD;
  while(temp != NULL)
  {
    cout << temp -> info << endl;
    temp = temp -> next;
  }
}

bool List :: retrieve(int element, Node* &outputPtr){
  Node* temp;
  temp = HEAD;
  while ((temp != NULL) && (temp ->info != element))
  {
    temp = temp -> next;
  }
  if (temp == NULL)
    return false;
  else
  {
    outputPtr = temp;
    return true;
  }
}


int main(){
  Node* outputPtr;

  List  obj;
  cout <<  obj.isEmpty() << endl;
   
   obj.addtoHead(1);
   obj.addtoHead(2);
   obj.addtoHead(3);
   obj.addtoHead(4);
   obj.addtoTail(13);
   obj.traverse();
   cout<<"\n";
   obj.remove(3);
   obj.remove(2);
   obj.traverse();
   cout<<"\n";
   cout <<  obj.search(1) << endl;   // returns 1 if found
   cout <<  obj.search(0) << endl;   // returns 0 if not found
   
   obj.retrieve(1, outputPtr);
   obj.add(69, outputPtr);
   obj.removefromHead();
   obj.traverse();
   
   
  return 0;
}