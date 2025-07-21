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
        while (H[i] > 0) {
            T++;
            if (T % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}