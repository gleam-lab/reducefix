#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll T = 0;
    int idx = 0;

    while (idx < n) {
        T++;
        // Only attack if current enemy has health > 0
        if (h[idx] > 0) {
            if (T % 3 == 0) {
                h[idx] -= 3;
            } else {
                h[idx]--;
            }
        }
        // Move to next enemy if current one is dead
        while (idx < n && h[idx] <= 0) {
            idx++;
        }
    }

    cout << T << endl;
}