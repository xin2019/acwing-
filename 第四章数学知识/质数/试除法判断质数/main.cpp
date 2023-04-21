#include<iostream>
using namespace std;
bool is_prime(int n){
    if(n < 2 )
        return false;
    for(int i = 2; i <= n/i; i++ ) {
        if(n%i == 0)
            return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    while(n--) {
        int temp;
        cin >> temp;
        cout<< (is_prime(temp) == true? "Yes": "No") << endl;
    }
    return 0;
}
