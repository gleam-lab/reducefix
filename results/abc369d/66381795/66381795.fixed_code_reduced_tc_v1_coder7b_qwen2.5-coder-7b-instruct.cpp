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
    for (int i = 0; i < n - 1; i += 2) {
        sum += max(data[i], data[i + 1]) * 2;
    }
    if (n % 2 != 0) {
        sum += data[n - 1];
    }

    cout << sum << endl;
    return 0;
}