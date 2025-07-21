#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> H(n);
    for (ll i = 0; i < n; i++) {
        cin >> H[i];
    }
    
    ll T = 0;
    for (ll i = 0; i < n; i++) {
        ll cycles = H[i] / 5;
        T += cycles * 3;
        ll remaining = H[i] % 5;
        
        while (remaining > 0) {
            T++;
            if (T % 3 == 0) {
                remaining -= 3;
            } else {
                remaining -= 1;
            }
        }
    }
    
    cout << T << endl;
    return 0;
}