/*
牵扯到数学知识，不会，代码也没看懂。
*/

#include<iostream>
#include<cstdio>
using namespace std;
 
int main()
{
    for (double x=0; x<=2.0; x+=0.001)
    {
        double sum = 0;
        for (int k=1; k<5000; k++)
            sum += (1-x)/(k * (k + 1) * (k + x));
        sum += (1-x)/(2 * 5000 * 5000) + 1.0;
        printf("%5.3lf %16.12lf\n",x,sum);
    }
    return 0;
}

