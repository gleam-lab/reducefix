#include <bits/stdc++.h>
using namespace std;

const int MAXN = 400005;
long long n, m, a[MAXN], w[MAXN], t[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    long long an = 0;
    for (int i = 1; i < 2 * n; i++) {
        w[i + 1] = (w[i] + a[i]) % m;
        if (i > n) t[w[i - n]]--;
        if (i >= n) {
            an += t[w[i]];
        }
        t[w[i]]++;
    }
    
    cout << an << endl;
    return 0;
}