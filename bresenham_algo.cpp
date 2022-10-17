#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int x1,y1,x2,y2,dx,dy,d;
    float xinc,yinc,xnext,ynext;
    cout<<"Enter the values of x1,y1,x2,y2\n";
    cin>>x1>>y1>>x2>>y2;
    dx=x2-x1;
    dy=y2-y1;
    d=(2*dy)-dx;
    while (x1!=x2)
    {
        cout<<"("<<x1<<","<<y1<<")";
        if (d>=0)
        {
            d+=(2*dy)-(2*dx);
            y1++;
            x1++;
        }
        else
        {
            d+=(2*dy);
            x1++;
        }
        
    }
    
    return 0;
}