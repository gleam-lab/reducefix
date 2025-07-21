#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m, a[N * 2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    long long res = 0;
    vector<int> cnt(m, 0);
    cnt[0] = 1; // prefix sum mod m == 0 occurs once initially

    long long prefix = 0;
    for (int i = 1; i < 2 * n; ++i) {
        prefix += a[i];
        int mod = (prefix % m + m) % m; // Ensure non-negative mod

        res += cnt[mod];
        if (i < n) {
            cnt[mod]++;
        } else {
            cnt[mod]--;
        }
    }

    cout << res << endl;
    return 0;
}