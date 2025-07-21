#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll t = 0;
    bool done = false;

    while (!done) {
        done = true;
        rep(i, n) {
            if (a[i] <= 0) continue;
            done = false;
            if ((t + 1) % 3 == 0) {
                a[i] -= 3;
            } else {
                a[i]--;
            }
            t++;
        }
    }

    cout << t << "\n";

    return 0;
}