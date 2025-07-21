#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    
    ll t = 0;
    while (true) {
        bool all_zero = true;
        rep(i, n) {
            if (h[i] > 0) {
                all_zero = false;
                if ((t + 1) % 3 == 0) {
                    h[i] -= 3;
                } else {
                    h[i]--;
                }
            }
        }
        t++;
        if (all_zero) break;
    }
    
    cout << t - 1 << endl; // Subtract 1 because we increment t one extra time after all enemies are defeated
    
    return 0;
}