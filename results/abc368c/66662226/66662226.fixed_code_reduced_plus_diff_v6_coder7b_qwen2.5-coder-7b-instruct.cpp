#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    long long t = 0;
    int front = 0;
    
    while (true) {
        bool done = true;
        for (int i = front; i < n; ++i) {
            if (h[i] > 0) {
                done = false;
                break;
            }
        }
        if (done) break;

        if ((t + 1) % 3 == 0) {
            for (int i = front; i < n; ++i) {
                if (h[i] > 0) {
                    h[i] -= 3;
                    if (h[i] <= 0) front = i + 1;
                }
            }
        } else {
            for (int i = front; i < n; ++i) {
                if (h[i] > 0) {
                    h[i] -= 1;
                    if (h[i] <= 0) front = i + 1;
                }
            }
        }

        ++t;
    }

    cout << t << '\n';
}