#include<iostream>
using namespace std;
int BiToDec(int number)
{
    int n=number;
    int decimalnum=0;
    int pow=1;// 2^0
    while(n>0)
    {
        int lastdigit = n%10;
        decimalnum = decimalnum + lastdigit * pow;
        pow=pow*2;
        n=n/10;
    }
    return decimalnum;

}
int main()
{
    int n;
    cin>>n;
    int result=BiToDec(n);
    cout<<result;

}