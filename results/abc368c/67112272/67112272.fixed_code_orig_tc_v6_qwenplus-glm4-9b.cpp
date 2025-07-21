#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    vector<long long> healths(n);
    rep(i, n) cin >> healths[i];

    sort(healths.begin(), healths.end(), greater<long long>());

    long long ans = 0;
    rep(i, n) {
        if (healths[i] % 3 == 0) {
            ans += healths[i] / 3;
        } else if (healths[i] % 3 == 1) {
            ans += healths[i] / 3 + 1;
        } else if (healths[i] % 3 == 2) {
            ans += healths[i] / 3 + 2;
        }
    }

    cout << ans << endl;
}