#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, m, k, sum, cnt, a[N], d[N];
unordered_map<int, int> b;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    b[0] = 1;
    long long total = 0;
    d[0] = 0;

    for (int i = 1; i <= 2 * n; ++i) {
        d[i] = (d[i - 1] + a[i]) % m;
        if (i > n) {
            b[d[i - n]]--;
        }
        total += b[d[i]];
        if (i < n) {
            b[d[i]]++;
        }
    }

    cout << total << endl;
    return 0;
}