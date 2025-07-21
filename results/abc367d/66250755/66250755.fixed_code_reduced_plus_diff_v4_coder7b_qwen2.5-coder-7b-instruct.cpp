#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 400005;

int n, m, a[MAXN], t[MAXN * 2], an, w[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    for (int i = 1; i < 2 * n; ++i) {
        w[i + 1] = (w[i] + a[i]) % m;
        if (i > n) --t[w[i - n]];
        if (i >= n) an = (an + t[w[i]]) % MOD;
        ++t[w[i]];
    }
    cout << an << endl;
    return 0;
}