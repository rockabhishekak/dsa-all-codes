#include<iostream>
using namespace std;
#define SIZE 10
int hashTable[SIZE];
//  Initialize hash table
void initTable()
{
    for(int i=0;i<SIZE;i++)
        hashTable[i]=-1;
}
// insert element using linear probing
void insert(int key)
{
    int index=key%SIZE;
    if(hashTable[index]==-1)
        {
            hashTable[index]=key;
            cout<<"Inserted "<<key<<" at index "<<index<<endl;
        }
        else
        {
            for(int i=1;i<SIZE;i++)
            {
                int newIndex=(index+i)%SIZE;
                if(hashTable[newIndex]==-1)
                {
                    hashTable[newIndex]=key;
                    // cout<<"Inserted "<<key<<" at index "<<newIndex<<endl;
                    return;
                }
            }
            cout<<"Hash table is full."<<endl;
        }
}
// display hash table

void display()
{
    cout<<"Hash Table:"<<endl;
    for(int i=0;i<SIZE;i++)
    {
        if(hashTable[i]!=-1)
            cout<<i<<" --> "<<hashTable[i]<<endl;
        else
            cout<<i<<" --> "<<"NULL"<<endl;
    }
}
// search element
bool search(int key)
{
    int index=key%SIZE;
    if(hashTable[index]==key)
        return true;
    else
    {
        for(int i=1;i<SIZE;i++)
        {
            int newIndex=(index+i)%SIZE;
            if(hashTable[newIndex]==key)
                return true;
            if(hashTable[newIndex]==-1)
                return false;
        }
        return false;
    }
}
int main()
{
    int n,key,searchKey;
    initTable();
    cout<<"Enter number of elements to insert: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++)
    {
        cin>>key;
        insert(key);
    }
    display();
    cout<<"Enter element to search: ";
    cin>>searchKey;
    if(search(searchKey))
        cout<<searchKey<<" found in hash table."<<endl;
    else
        cout<<searchKey<<" not found in hash table."<<endl;
    return 0;
}