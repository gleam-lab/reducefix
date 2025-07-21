#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll num_attack(ll t, ll h) {
    ll cnt = 0;
    while(h > 0){
        if(t % 3 == 0){
            h -= 3;
        } else{
            h -= 1;
        }
        cnt++;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    ll t = 0;
    for (int i = 0; i < n; ++i) {
        ll h;
        cin >> h;
        t += num_attack(t, h);
    }
    
    cout << t << endl;
}