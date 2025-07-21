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
    rep(i, n) {
        cin >> data[i];
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if ((i + 1 < n && data[i + 1] * 2 > data[i] + data[i + 1]) || (i == n - 1)) {
            sum += data[i];
        } else {
            sum += data[i] * 2;
        }
    }

    cout << sum << endl;
    return 0;
}