#include<iostream>
using namespace std;
int DecToBi(int number)
{
    int n=number;
    int binary=0;
    int pow=1;// 2^0
    while(n>0)
    {
        int lastdigit = n%2;
        binary += lastdigit * pow;
        pow = pow * 10;

        
        n=n/2;
    }
    return binary;

}
int main()
{
    int n;
    cin>>n;
    int result=DecToBi(n);
    cout<<result;

}