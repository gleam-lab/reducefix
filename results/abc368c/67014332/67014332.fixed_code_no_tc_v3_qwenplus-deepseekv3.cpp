#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> H(n);
    for (ll &h : H) cin >> h;
    
    ll T = 0;
    for (ll h : H) {
        // Calculate the number of full 3-damage cycles (3 turns per cycle)
        ll cycles = h / 5;
        T += cycles * 3;
        ll remaining = h % 5;
        
        if (remaining == 0) continue;
        
        // Simulate the remaining attacks
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