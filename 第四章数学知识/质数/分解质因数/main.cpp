#include<iostream>
using namespace std;
void get_divisors(int n) {
    for(int i = 2; i <= n / i; i++) {
        if(n % i == 0) {
            int s = 0;
            while(n % i == 0) {
                n /= i;
                s++;
            }
            cout << i << " " << s << endl;
        }
    }
    if(n > 1)
        cout << n << " 1" << endl;
}
int main(){
    int n;
    cin >> n;
    while(n--) {
        int temp;
        cin >> temp;
        get_divisors(temp);
        cout << endl;
    }
    return 0;
}
