#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;

int n, m, a[MAXN], t[MAXN * 2], an, w[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    long long sum = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        sum += a[i];
        w[i] = sum % m;
        if (i > n) {
            an += t[w[i - n]];
        }
        t[w[i]]++;
    }

    cout << an << endl;
    return 0;
}