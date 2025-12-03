#include<stdio.h>
void toh(int n,char source,char auxiliary,char destination)
{
    if(n==1)
    {
        printf("Move disk 1 from rod %c to rod %c\n",source,destination);
        return;
    }
    toh(n-1,source,destination,auxiliary);
    printf("Move disk %d from rod %c to rod %c\n",n,source,destination);
    toh(n-1,auxiliary,source,destination);
}
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    toh(n,'A','B','C'); // A, B and C are names of rods
    return 0;
}