#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
double a,b,c,d;
double f(double x){
    return a*x*x*x+b*x*x+c*x+d;
}
int main(){
    cin>>a>>b>>c>>d;
    double i,l,r;
    for(i=-100;i<=100;i++){
        l=i,r=i+1;
        if(f(l)*f(r)==0){
            if(f(l)==0){
                printf("%.2lf ",l);
            }
        }else if(f(l)*f(r)<0){
            while(fabs(r-l)>=1e-4){
                double mid=(l+r)/2;
                if(f(l)*f(mid)<0)
                    r=mid;
                else
                    l=mid;
            }
            printf("%.2lf ",l);
        }
    }
    cout<<endl;
    return 0;
}

