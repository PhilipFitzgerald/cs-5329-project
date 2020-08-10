#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
  head=NULL;
 
}
void LinkedList::addNode(int x)
{
  Node * temp =  new Node;
  temp->data=x;
  temp->next=NULL;
  if (head==NULL)
  {
   head=temp;
  }
  else {
   Node *p=head;
    while(p->next)
    {
      p=p->next;
    }
    p->next=temp;
  }
}
void LinkedList::printList()
{
Node *temp=head;

while (temp)
{
  cout<<temp->data;
  if (temp->next)
      cout<< " --> ";
  temp=temp->next;
}
}
void LinkedList::deleteNode(int x)
{
  Node *f=head;
  Node *b=NULL;
  if (head==NULL)
  return ;
  while (f && f->data !=x)
  {
    b=f;
    f=f->next;
  }
  if (f)
  { if (f==head)
    {
        head=f->next;
        delete f;
    }else{
      b->next=f->next;
      delete f;
    }
  }
  
  return ;
}
bool LinkedList::checkValue()
{
  if (head!=NULL)
  return true;
  else 
  return false;
}
int LinkedList:: search(int x)
{
  Node *p=head;
  int counter=1;

  while (p && p->data !=x)
  {
    counter++;
    p=p->next;
  }
  if (p)
  return counter;
  else
  return 0;
}
