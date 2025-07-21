#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }
    
    ll T = 0;
    for (int i = 0; i < n; ++i) {
        ll h = H[i];
        // Calculate the number of full triple attacks (3 damage each)
        ll full_cycles = h / 3;
        ll remaining = h % 3;
        
        // Each full cycle takes 3 attacks, but we need to see if they fit into the current T sequence
        T += full_cycles * 3;
        h -= full_cycles * 3;
        
        // Now handle the remaining health
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