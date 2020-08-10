class LinkedList {

private:
struct Node{
int data;
Node * next;
};
Node * head;

public:
LinkedList();
void addNode(int x);
void printList();
void deleteNode(int x);
bool checkValue();
int search(int x);
};
