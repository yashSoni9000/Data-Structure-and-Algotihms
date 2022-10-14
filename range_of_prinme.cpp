#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool prime(int num)
{
    if(num<=1)
    return false;
    for(int j=2;j<=sqrt(num);j++)
    {
        if(!(num%j))
        return false;
    }
    return true;
}
int main()
{
    int ll ,ul,count=0,sum=0;
    cin>>ll>>ul;
    for(int i=ll;i<=ul;i++)
    {
        if(prime(i))
        {
            count++;
            sum+=i;
        }       
    }
    cout<<"SUM = "<<sum<<"\nCOUNT = "<<count<<endl;
    return 0;
}