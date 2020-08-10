#include <iostream>
#include "LLST.h"
#include <string>
using namespace std;
LLST::LLST()
{
  head=NULL;
 
}
void LLST::addNode(string x)
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
void LLST::printList()
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
bool LLST::checkValue()
{
  if (head!=NULL)
  return true;
  else 
  return false;
}

void LLST::deleteNode(string x)
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
int LLST::search(string x)
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
