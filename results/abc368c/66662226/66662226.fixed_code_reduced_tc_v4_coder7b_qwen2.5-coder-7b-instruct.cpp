#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) {
        cin >> h[i];
    }

    ll t = 0;
    while (true) {
        bool done = true;
        for (int i = 0; i < n; ++i) {
            if (h[i] > 0) {
                done = false;
                if ((t + 1) % 3 == 0) {
                    h[i] -= 3;
                } else {
                    h[i]--;
                }
                t++;
                if (h[i] <= 0) {
                    h[i] = 0;
                }
            }
        }
        if (done) break;
    }

    cout << t << endl;
}