#include<bits/stdc++.h>
using namespace std;

const int MAXN = 400005;

int n, m, a[MAXN], t[MAXN], an, w[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    memset(t, 0, sizeof(t));
    t[0] = 1; // Initialize with one occurrence of sum 0
    for (int i = 1; i < 2 * n; i++) {
        w[i] = (w[i - 1] + a[i]) % m;
        if (i > n) {
            t[w[i - n]]--;
        }
        if (i >= n) {
            an += t[w[i]];
        }
        t[w[i]]++;
    }
    cout << an;
    return 0;
}