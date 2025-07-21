#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> H(n);
    rep(i, n) cin >> H[i];

    ll T = 0;

    // We'll simulate the process enemy by enemy
    for (int i = 0; i < n; ++i) {
        // How many attacks does this enemy need?
        ll h = H[i];
        
        // Each group of 3 attacks deals:
        // - One attack of 3 damage (on T % 3 == 0)
        // - Two attacks of 1 damage (T % 3 != 0)
        // Total damage per group: 5
        // So we can calculate full groups and remaining damage

        // Full groups of 3 attacks
        ll full_groups = h / 5;
        T += full_groups * 3;
        h -= full_groups * 5;

        // Remaining damage needed
        if (h > 0) {
            // We need to apply damage one attack at a time
            while (h > 0) {
                T++;
                if (T % 3 == 0)
                    h -= 3;
                else
                    h -= 1;
            }
        }
    }

    cout << T << endl;
}