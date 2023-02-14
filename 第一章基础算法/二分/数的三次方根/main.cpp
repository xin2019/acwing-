#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    double n;
    while(cin>>n){
        double l,r;
        l=-10000;
        r=10000;
        while(r-l>1e-8){
            double mid=(l+r)/2;
            if(mid*mid*mid<=n)
                l=mid;
            else
                r=mid;
        }
        printf("%.6lf\n",l);
    }

    return 0;
}
