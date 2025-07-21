#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> H(N);
    for (ll i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    ll T = 0;
    vector<ll> attacks(N, 0);
    
    for (ll i = 0; i < N; ++i) {
        ll remaining = H[i] - attacks[i] * 1;
        if (remaining <= 0) continue;
        
        ll full_cycles = (remaining + 2) / 3;
        T += full_cycles * 3;
        attacks[i] += full_cycles * 2; // Each full cycle consists of 2 1-damage attacks and 1 3-damage attack
        
        if (i + 1 < N) {
            attacks[i + 1] += full_cycles;
        }
        if (i + 2 < N) {
            attacks[i + 2] += full_cycles;
        }
    }
    
    cout << T << endl;
    return 0;
}