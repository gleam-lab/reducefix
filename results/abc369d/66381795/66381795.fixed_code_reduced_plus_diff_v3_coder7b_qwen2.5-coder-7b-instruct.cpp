#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> data(n);
    rep(i, n) cin >> data[i];

    ll sum = 0;
    rep(i, n) {
        if ((i + 1) % 2 == 1) {
            sum += data[i];
        } else {
            sum += min(2LL * data[i], data[i - 1] + data[i]);
        }
    }

    cout << sum << '\n';
    return 0;
}