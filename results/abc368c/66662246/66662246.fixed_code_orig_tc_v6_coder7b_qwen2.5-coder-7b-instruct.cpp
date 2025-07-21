#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];

    long long ans = 0;
    for (long long &x : a) {
        while (x > 0) {
            ++ans;
            if (ans % 3 == 0) {
                x -= 3;
            } else {
                --x;
            }
        }
    }

    cout << ans << '\n';
}