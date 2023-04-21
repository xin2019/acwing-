#include <iostream>
#include<cstring>
using namespace std;
const int N = 110;
bool st[N];
int primes[N], cnt;
int n;
void get_divisors(int n) {
    for(int i = 2; i <= n/i; i++){
        if(n%i == 0){
            int s=0;
            while(n%i == 0){
                n /= i;
                s++;
            }
            cout << i << ' '<< s << endl;
        }
    }
    if(n > 1)
        cout << n << " 1" <<endl;
}
int main() {
    cin >> n;
    while(n--) {
        int temp;
        memset(primes, 0, sizeof primes);
        memset(st, false, sizeof st);
        cin >> temp;
        get_divisors(temp);
        cout << endl;
    }
    return 0;
}
