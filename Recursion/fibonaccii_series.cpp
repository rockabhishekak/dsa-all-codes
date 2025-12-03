#include<iostream>
using namespace std;
//void
int  fibonacci(int n)
{
    //non-recursive approach
    // int t1=0,t2=1,nextTerm;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<t1<<" ";
    //     nextTerm=t1+t2;
    //     t1=t2;
    //     t2=nextTerm;
    // }
    //recursive approach
    // static int t1=0,t2=1,nextTerm;
    // if(n>0)
    // {
    //     cout<<t1<<" ";
    //     nextTerm=t1+t2;
    //     t1=t2;
    //     t2=nextTerm;
    //     fibonacci(n-1);
    // }

    //better recursive approach
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
    
    
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<fibonacci(i)<<" ";
    }

    return 0;
}