//To Implement printing of n natural numbers.
#include<iostream>
using namespace std;
void natural(int n)
{
    if(n==0)
    {
        return;
    }
    natural(n-1);
    cout<<n<<" ";
}
int main()
{
    int n;
    cin>>n;
    natural(n);
    return 0;
}