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
    while (true) {
        bool changed = false;
        for (int &x : h) {
            if (x > 0) {
                ++t;
                if (t % 3 == 0) x -= 3;
                else x--;
                changed = true;
            }
        }
        if (!changed) break;
    }

    cout << t << endl;
}