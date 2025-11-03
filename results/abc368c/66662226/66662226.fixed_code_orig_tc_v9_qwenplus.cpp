#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) {
        cin >> h[i];
    }

    ll T = 0;
    int enemy_idx = 0;

    while (enemy_idx < n) {
        T++;
        // Skip enemies that are already defeated
        while (enemy_idx < n && h[enemy_idx] <= 0) {
            enemy_idx++;
        }
        
        if (enemy_idx >= n) break;
        
        // Attack the frontmost alive enemy
        if (T % 3 == 0) {
            h[enemy_idx] -= 3;
        } else {
            h[enemy_idx]--;
        }
    }

    cout << T << endl;
    return 0;
}