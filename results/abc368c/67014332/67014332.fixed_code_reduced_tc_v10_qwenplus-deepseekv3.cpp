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
    for (ll i = 0; i < N; ++i) {
        ll h = H[i];
        // Number of full 3-attack cycles (each dealing 5 damage)
        ll full_cycles = h / 5;
        T += full_cycles * 3;
        h %= 5;
        
        // Handle the remaining health
        while (h > 0) {
            T++;
            if (T % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}