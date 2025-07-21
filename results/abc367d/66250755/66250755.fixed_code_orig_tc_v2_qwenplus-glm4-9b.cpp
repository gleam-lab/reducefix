#include<bits/stdc++.h>
using namespace std;
int n, m, a[400005], t[400005], an;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        t[(i + n - 1) % m] = (t[(i + n - 1) % m] + a[i]) % m;
    }
    an = 0;
    for (int i = 0; i < m; i++) {
        if (t[i] >= n) {
            an += (t[i] - n + 1);
        }
    }
    cout << an << endl;
    return 0;
}