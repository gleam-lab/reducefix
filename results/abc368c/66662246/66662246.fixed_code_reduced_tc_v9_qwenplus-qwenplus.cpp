#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 0;
    rep(i, n)
    {
        ll h = a[i];
        // Each 3 turns: two 1-damage attacks and one 3-damage attack
        // Total damage per cycle of 3 turns = 5
        ll cycles = h / 5;
        ans += cycles * 3;
        h -= cycles * 5;

        // Handle remaining health
        if (h > 0) {
            ans++; // First attack
            h--;
            if (h > 0) {
                ans++; // Second attack
                h--;
                if (h > 0) {
                    ans++; // Third attack
                }
            }
        }
    }

    cout << ans << endl;
}