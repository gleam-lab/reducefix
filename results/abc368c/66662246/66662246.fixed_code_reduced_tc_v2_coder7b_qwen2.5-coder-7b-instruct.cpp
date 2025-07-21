#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    ll t = 0;
    bool changed;
    do {
        changed = false;
        rep(i, n) {
            if (h[i] > 0) {
                t++;
                if (t % 3 == 0) {
                    h[i] -= 3;
                } else {
                    h[i]--;
                }
                changed = true;
            }
        }
    } while (changed);

    cout << t << endl;
}