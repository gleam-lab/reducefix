#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> h(n);
    rep(i, n) cin >> h[i];

    long long t = 0;
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
        if (all_zero) break;
        t++;
    }

    cout << t << '\n';

    return 0;
}