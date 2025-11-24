#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node *insert_beg(Node* top,int val)
{
    Node* nn= new Node{val,top};
    top=nn;
    return top;
}
void Pop(Node* top)
{
    Node* ptr=top;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;

    }
}
void Top(Node* top)
{
    cout<<endl<<top->data;
}

int main()
{
    int val;
    Node* top=nullptr;
    cin>>val;
    while(val!=-1)
    {
        top=insert_beg(top,val);
        cin>>val;
    }
    Pop(top);
    Top(top);

}