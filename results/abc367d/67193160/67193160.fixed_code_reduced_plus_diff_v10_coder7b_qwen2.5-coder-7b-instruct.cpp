#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

int n, m, k, sum, cnt;
int a[MAXN], b[MAXN], d[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    b[0] = 1;
    for(int i = 1; i < 2 * n; ++i) {
        if(i >= n) {
            b[d[i - n] % m]--;
        }
        d[i] = (d[i - 1] + a[i]) % m;
        sum = (sum + b[d[i]]) % MOD;
        if(i < n) {
            b[d[i]]++;
        }
    }

    cout << sum << '\n';
    return 0;
}