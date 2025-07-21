#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> h(n);
    rep(i, n) {
        cin >> h[i];
    }

    long long t = 0;
    while (true) {
        bool any_changed = false;
        rep(i, n) {
            if (h[i] > 0) {
                if (t % 3 == 0) {
                    h[i] -= 3;
                } else {
                    h[i]--;
                }
                if (h[i] <= 0) {
                    any_changed = true;
                }
            }
        }
        if (!any_changed) break;
        t++;
    }

    cout << t << endl;

    return 0;
}