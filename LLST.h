#include <iostream>
using namespace std;
class LLST {

private:
struct Node{
string data;
Node * next;
};
Node * head;

public:
LLST();
void addNode(string x);
void printList();
bool checkValue();
void deleteNode(string x);
int search(string x);
};
