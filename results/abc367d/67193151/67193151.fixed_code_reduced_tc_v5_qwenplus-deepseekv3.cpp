#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m, sum, cnt, a[2 * N], d[2 * N];
int freq[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    freq[0] = 1;
    long long result = 0;

    for (int i = 1; i < 2 * n; i++) {
        if (i > n) {
            freq[d[i - n] % m]--;
        }
        d[i] = d[i - 1] + a[i];
        result += freq[d[i] % m];
        if (i < n) {
            freq[d[i] % m]++;
        }
    }

    cout << result;
    return 0;
}