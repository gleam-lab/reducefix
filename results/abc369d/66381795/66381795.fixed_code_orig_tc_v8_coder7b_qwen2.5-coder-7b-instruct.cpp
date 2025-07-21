#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> data(n);
    rep(i, n) cin >> data[i];

    long long sum = 0;
    rep(i, n) {
        if ((i + 1) % 2 == 0 && data[i] != data[i + 1]) {
            sum += max(0LL, 2 * data[i + 1] - data[i]);
        } else {
            sum += data[i];
        }
    }

    cout << sum << '\n';
    return 0;
}