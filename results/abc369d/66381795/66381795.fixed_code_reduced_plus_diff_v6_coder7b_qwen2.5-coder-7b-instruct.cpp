#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> data(n);
    rep(i, n) {
        cin >> data[i];
    }

    ll sum = 0;
    rep(i, n) {
        if ((i + 1) % 2 == 0) {
            sum += min(2 * data[i], data[i] + data[i + 1]);
        } else {
            sum += data[i];
        }
    }

    cout << sum << endl;
    return 0;
}