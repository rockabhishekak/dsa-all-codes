#include<iostream>
using namespace std;
int main()
{
    //number pyramid pattern
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    //char pyramid pattern
    char k='A';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<k++<<" ";
        }
        cout<<endl;
    }

}