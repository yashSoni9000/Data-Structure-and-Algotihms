#include <bits/stdc++.h>
using namespace std;
 
void DDALine(int xi, int yi, int x1, int y1)
{

    int dx = x1 - xi;
    int dy = y1 - yi;
 
    int step;

    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);
 
    
    float x_incr = (float)dx /step;
    float y_incr = (float)dy /step; 

    float x = xi;
    float y = yi;
 
    for (int i = 0; i < step; i++) {

        x+= x_incr;
        y+=y_incr;

        cout<<round(x)<<" "<<round(y)<<endl;
    }
}
 
int main()
{
 
    int xi,yi,x1,y1;
    cin>>xi>>yi>>x1>>y1;
    DDALine(x0, y0, x1, y1);
 
    return 0;
}
