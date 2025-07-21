#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (ll i=0;i < (n); i++)
using ll = long long;

int main() {
    int n; cin >> n;
    ll total_attacks = 0;
    vector<ll> h(n);
    
    rep(i, n) {
        cin >> h[i];
        if (h[i] == 0) continue;
        if (h[i] % 3 == 0) {
            total_attacks += h[i] / 3;
        } else if (h[i] % 3 == 1) {
            total_attacks += h[i] / 3 + 2;  // Attacks as if it's 3 health more (increasing T by 1 extra time)
        } else {  // h[i] % 3 == 2
            total_attacks += (h[i] - 2) / 3 + 2;  // If less than 3 health, treat as 2 health more
        }
    }
    
    cout << total_attacks << endl;
}