#include <iostream>
#include "LinkedList.h"
#include <stdlib.h>
#include <cmath>
#include "LLST.h"
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

double loadFactor=0; // for tracking load factor
int countIT=0; // for tracking number of keys 
////////////////////////////////////////////////////
////////////////linked list collisions//////////////
///////////////////////////////////////////////////
int hashFunction(int x, int size)
{
  int index;
  index=rand() % size +0;
  return index;
}
/// random key generator 
int randomIntVal ()
{ int val;
  val=rand() % 500 +1; 
  return val;
}

int randomIntValTwo ()// for strings
{
  int val=rand() % 26 +0;
  return val;
}
void printIntTable(LinkedList hashTable[], int hashTableSize)
{
  for (int i = 0; i <hashTableSize; i++) // printing array of linked lists and each node of lists
  {
   if (hashTable[i].checkValue())
    { cout<<"index "<<i<<":     ";
      hashTable[i].printList(); 
      cout<<endl;
    }
  }   
}
void addIntLinked(LinkedList hashTable[], int hashTableSize,int numberOfValues) // rename to insert
{
  int index; // for tracking returned hash index
  int val;
  srand(time(0)); 
  for (int i = 0; i<numberOfValues; i++) // finding index and adding to linked list
    {
    val=randomIntVal ();
    index=hashFunction(val, hashTableSize); // find index to place item
    hashTable[index].addNode(val); //place value into index
  }
  
}
void printStringTable(LLST hashTableTwo[], int hashTableSize)
{
  for (int i = 0; i <hashTableSize; i++) // printing array of linked lists and each node of lists
  {
   if (hashTableTwo[i].checkValue())
    { cout<<"index "<<i<<":     ";
      hashTableTwo[i].printList(); // works
      cout<<endl;
    }
  }
   
}
void addStringLinked(LLST hashTableTwo[], int hashTableSize, int numberOfValues, string arr[])

{
  int index; // for tracking returned hash index
  int val=-1;
  srand(time(0)); 
  for (int i = 0; i<numberOfValues; i++) // finding index and adding to linked list
    {
    val=randomIntValTwo ();
    index=hashFunction(val, hashTableSize); // find index to place item
    hashTableTwo[index].addNode(arr[val]); //place value into index
  }

}
void askForIntLinkedSearch(LinkedList hashTable[], int hashTableSize)
{
  int responseSearch, valueSearch;
     cout<<"Would you like to search for a value? 1 for yes 2 for no"<<endl;
      cin>>responseSearch;
      if (responseSearch==1)
      {
        cout<<"What value 0-1000? ";
        cin>>valueSearch;
        cout<<"the values are located in: "<<endl;
                 for (int i = 0; i<hashTableSize; i++)
                {
                 if(hashTable[i].search(valueSearch)!=0)
                  {
                    cout<<"Array Index(s) "<<i<<":  Linked Index(s): " <<hashTable[i].search(valueSearch)-1; 
                        cout<<endl; 
                  }
              }
      }  
}
void askForIntLinkedDelete(LinkedList hashTable[], int hashTableSize)
{
  int response, valueDelete;
  cout<<"Would you like to delete a value? 1 for yes 2 for no"<<endl;
      cin>>response; 
  if (response==1)
      {
        cout<<"What value 0-1000? ";
        cin>>valueDelete;
       for (int i = 0; i<hashTableSize; i++)
        {
          hashTable[i].deleteNode(valueDelete); // works now
        }
            cout<<endl<<endl;   
      printIntTable(hashTable,hashTableSize);cout<<endl<<endl;

      } 
}
void askForSTRLinkedSearch(LLST hashTableTwo[], int hashTableSize)
{
 int responseSearch;
 string valueSearch;
     cout<<"Would you like to search for a string? 1 for yes 2 for no"<<endl;
      cin>>responseSearch;
      if (responseSearch==1)
      {
        cout<<"What value A-Z? ";
        cin>>valueSearch;
        cout<<"the values are located in: "<<endl;
                 for (int i = 0; i<hashTableSize; i++)
                {
                 if(hashTableTwo[i].search(valueSearch)!=0)
                  {
                    cout<<"Array Index(s) "<<i<<":  Linked Index(s): " <<hashTableTwo[i].search(valueSearch)-1; 
                        cout<<endl; 
                  }
              }
      }  
}
void askForSTRLinkedDelete(LLST hashTableTwo[], int hashTableSize)
{
    int response; 
    string valueDelete;
  cout<<"Would you like to delete a value? 1 for yes 2 for no"<<endl;
      cin>>response; 
  if (response==1)
      {
        cout<<"What value A-Z? ";
        cin>>valueDelete;
       for (int i = 0; i<hashTableSize; i++)
        {
          hashTableTwo[i].deleteNode(valueDelete); // works now
        }
            cout<<endl<<endl;   
      printStringTable(hashTableTwo,hashTableSize);cout<<endl<<endl;

      } 
}

///////////////////////////////////////////////////
// ///////end linked list collisions/////////////
///////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////
//////////////// for open addressing collisions/////////////////////////
///////////////////////////////////////////////////////////////////////

int quadraticHash(int size, int key, int c1, int c2, int i )
{
int index=-1;

index=( key + (c1*(i))+ (c2*(i*i)) )%size; // check sheet to see if right

return index;
}
//int open addressing
int * initializeArray(int arr[], int size)
{

  for (int i =0; i<size; i++)
  {
    arr[i]=-1;
  }
  return arr;
}
//int open addressing
int* insertINT (int arr3[], int sizeArray3, int key, int c1, int c2)
{
  int *arrayPTR=arr3;
  int index=-1;
  
  
  for (int i =0; i <(sizeArray3); i++)
  {
    index=quadraticHash(sizeArray3, key, c1, c2, i);
   
    if (arrayPTR[index]==-1)
    {
      arrayPTR[index]=key;
      countIT++;
      return arrayPTR;
    }
  }
  
  return arrayPTR;
}
void printArrayOpen(int arr3[], int sizeArray3)
{
  for (int i=0; i<sizeArray3; i++)
  {if (arr3[i]!=-1)
   cout<<"index " << i <<": "<< arr3[i]<<endl;
  } 

}
void searchOpenAddress(int arr3[], int sizeArray3 )
{
  int value, reply;
  cout<<"Would you like to search for a whole number? 1 for yes 2 for no"<<endl;
  cin>>reply;

  if (reply==1)
  {
    cout<<"what number?"<<endl;
    cin>>value;
    for (int i =0; i<sizeArray3; i++)
    {
     if (arr3[i]==value)
      cout<<"This value is in index(s) "<<i<<endl;
    }
  }
}
void deleteOpenAddress(int arr3[], int sizeArray3)
{
  int reply, value;
  cout<<"Would you like to delete a whole number from the table? 1 for yes 2 for no"<<endl;
  cin>>reply;

  if (reply ==1)
  {
    cout<<"what value?"<<endl;
    cin>>value;
    cout<<"The value in the folowing index(s) was deleted:"<<endl;
    for (int i=0; i<sizeArray3; i++)
    {
      if (arr3[i]==value)
      {
        cout<<"index: "<<i<<endl;
        arr3[i]=-1;
      }
    }

  } 
//cout<<endl;
//printArrayOpen(arr3,sizeArray3);
}
// string open addressing
string * initializeArray(string arr[], int size)
{
  for (int i =0; i<size; i++)
  {
    arr[i]=" ";
  }
  return arr;
}
// string open addressing
string * insert(string home[], int sizeArray3,int key, int c1, int c2,string arr[])
{
 string *arrayPTR=home;
  int index=-1;

  for (int i =0; i <(sizeArray3/2); i++)
  {
    index=quadraticHash(sizeArray3, key,c1, c2, i);
    if (arrayPTR[index]==" ")
    {
      arrayPTR[index]= arr[key];
      countIT++;
     return arrayPTR;
    }
  }
  return arrayPTR;
}

void printArrayOpen(string arr3[], int sizeArray3)
{
  for (int i=0; i<sizeArray3; i++)
  {
    if (arr3[i]!=" ")
   cout<<"index " << i <<": "<< arr3[i]<<endl;
  } 

}
void searchOpenAddress(string arr3[], int sizeArray3 )
{
  string value; 
  int reply;
  cout<<"Would you like to search for a string? 1 for yes 2 for no"<<endl;
  cin>>reply;

  if (reply==1)
  {
    cout<<"what string?"<<endl;
    cin>>value;
    for (int i =0; i<sizeArray3; i++)
    {
     if (arr3[i]==value)
      cout<<"This value is in index: "<<i<<endl;
    }
  }
}
void deleteOpenAddress(string arr3[], int sizeArray3)
{
  int reply;
  string value;
  cout<<"Would you like to delete a string from the table? 1 for yes 2 for no"<<endl;
  cin>>reply;

  if (reply ==1)
  {
    cout<<"what string?"<<endl;
    cin>>value;
    cout<<"The value in the folowing index(s) was deleted:"<<endl;
    for (int i=0; i<sizeArray3; i++)
    {
      if (arr3[i]==value)
      {
        cout<<"index: "<<i<<endl;
        arr3[i]= " ";
      }
    }

  } 
}

///////////////////////////////////////////////////
// end open addressing collisions//////////////////
///////////////////////////////////////////////////
void menu(int responseOne,LinkedList hashTable[], int hashTableSize,LLST hashTableTwo[], string arr[])
{
  int responseTwo; 
  int valueDelete;
  int numberOfValues;
clock_t time_req;
    clock_t print;
    clock_t search;
    clock_t del;
 switch(responseOne)
 {
   case 1:
   cout<<"Enter how many whole numbers you want to add to the table "<<endl;
   cin>>numberOfValues;
loadFactor=static_cast<double>(numberOfValues)/hashTableSize;
                    time_req = clock();

     addIntLinked(hashTable, hashTableSize,numberOfValues);
      time_req = clock() - time_req;
            print= clock();
     printIntTable(hashTable,hashTableSize);cout<<endl<<endl;
       print= clock()-print;
      search= clock();

     askForIntLinkedSearch(hashTable,hashTableSize);
     search= clock()-search;
      del= clock();

     askForIntLinkedDelete(hashTable, hashTableSize); 
       del= clock()-del;
         	cout << "It took " << (float)time_req/CLOCKS_PER_SEC << " seconds to insert" << endl; 
     	cout << "It took " << (float)print/CLOCKS_PER_SEC << " seconds to print" << endl; 
    cout << "It took " << (float)search/CLOCKS_PER_SEC << " seconds to search" << endl; 
     	cout << "It took " << (float)del/CLOCKS_PER_SEC << " seconds to delete" << endl; 
          break;
   case 2:
        cout<<"Enter how many strings you want to add to the table "<<endl;
          cin>>numberOfValues;
          addStringLinked(hashTableTwo, hashTableSize, numberOfValues, arr);
          printStringTable(hashTableTwo,hashTableSize);
          askForSTRLinkedSearch(hashTableTwo,hashTableSize);
          askForSTRLinkedDelete(hashTableTwo, hashTableSize);
          break;
  default: break;
 }
}
void menuTwo(int choice, int sizeArray3, int arr3[], string home[], string arr[]){
  int value;
  	clock_t time_req;
    clock_t print;
    clock_t search;
    clock_t del;
  switch (choice)
  {
    case 3:
          initializeArray(arr3, sizeArray3);
            srand(time(0)); 
             time_req = clock();
          for (int i=0; i<(sizeArray3-(sizeArray3*.20)); i++)
            {
              value=randomIntVal();
              insertINT(arr3,sizeArray3,value , 1, 2);
            }  
                  time_req = clock() - time_req;
            print= clock();

             printArrayOpen(arr3,sizeArray3);
      print= clock()-print;
      search= clock();

              searchOpenAddress(arr3,sizeArray3);
                    search= clock()-search;
      del= clock();

              deleteOpenAddress(arr3,sizeArray3);
        del= clock()-del;

      	cout << "It took " << (float)time_req/CLOCKS_PER_SEC << " seconds to insert" << endl; 
     	cout << "It took " << (float)print/CLOCKS_PER_SEC << " seconds to print" << endl; 
    cout << "It took " << (float)search/CLOCKS_PER_SEC << " seconds to search" << endl; 
     	cout << "It took " << (float)del/CLOCKS_PER_SEC << " seconds to delete" << endl; 
       //cout<<countIT;
    break;
    case 4:
                 

          initializeArray(home, sizeArray3);
            srand(time(0)); 
          time_req = clock();
          for (int i=0; i<(sizeArray3-(sizeArray3*.20)); i++)
            {
              value=randomIntValTwo();
             insert(home,sizeArray3,value, 1,2,arr);
            }   
            time_req = clock() - time_req;
            print= clock();

         printArrayOpen(home,sizeArray3);
          print= clock()-print;
           search= clock();

          searchOpenAddress(home,sizeArray3 );
          search= clock()-search;
          del= clock();

          deleteOpenAddress(home, sizeArray3);
          del= clock()-del;
	cout << "It took " << (float)time_req/CLOCKS_PER_SEC << " seconds to insert" << endl; 
     	cout << "It took " << (float)print/CLOCKS_PER_SEC << " seconds to print" << endl; 
    cout << "It took " << (float)search/CLOCKS_PER_SEC << " seconds to search" << endl; 
     	cout << "It took " << (float)del/CLOCKS_PER_SEC << " seconds to delete" << endl; 
       //cout<<countIT<<endl;

    break;
    default:
      ;
  }
}


int main() {
  int val; //random number to be injected
  LinkedList * hashTable;
  LLST *hashTableTwo;
  int hashTableSize;
  cout<<"Enter an array size you would like to use"<<endl;
  cin>>hashTableSize;
  hashTable= new LinkedList[hashTableSize];
  hashTableTwo=new LLST[hashTableSize];
///////////////////////////////////////////////////////
string arr[]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
int responseOne;

int * arr3 = new int[hashTableSize];
string *arr4=new string [hashTableSize];

cout<<"1. I would like to see a integer hashtable with linked list collision resolution"<<endl
  <<"2. I would like to see a string hashtable with linked list collision resolution"<<endl
  <<"3. I would like to see a int hashtable with open addressing resolution"<<endl
  <<"4. I would like to see a string hashtable with open addressing resolution"<<endl;
cin>>responseOne;
if (responseOne==1 || responseOne==2)
{
menu(responseOne, hashTable,hashTableSize,hashTableTwo,arr);
}
else if (responseOne==3 || responseOne==4)
{

menuTwo(responseOne,hashTableSize, arr3,arr4, arr);//change sze name
}
else
  cout<<"Did not enter values 1, 2, 3, or 4 only ";
//loadFactor=static_cast<double>(countIT)/hashTableSize;
  //cout<<endl<<fixed<<setprecision(2)<<"Load Factor of "<<loadFactor;
}
