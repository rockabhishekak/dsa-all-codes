#include<iostream>
using namespace std;
int main()
{

    int n;
    cout<<"Enter the number : "<<endl;
    cin>>n;
    cout<<endl;

    //pyramid



    bool digit=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<digit<<" ";
            digit=!digit;
        }
        cout<<endl;
        
    }

}