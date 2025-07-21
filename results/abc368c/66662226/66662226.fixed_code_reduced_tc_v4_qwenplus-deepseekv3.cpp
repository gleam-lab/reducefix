#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];
    
    ll ans = 0;
    rep(i, n) {
        ll cycles = H[i] / 5;
        ans += cycles * 3;
        H[i] -= cycles * 5;
        
        while (H[i] > 0) {
            ans++;
            if (ans % 3 == 0) {
                H[i] -= 3;
            } else {
                H[i] -= 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}