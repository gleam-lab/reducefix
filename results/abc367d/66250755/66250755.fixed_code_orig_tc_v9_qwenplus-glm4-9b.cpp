#include<bits/stdc++.h>
using namespace std;
int n, m, a[400005], w[400005], t[1000005], an, w_pos[400005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
        w[i + n] = 0;
    }
    for (int i = 1; i <= n; i++) {
        w[i] = a[i];
        t[a[i]]++;
        w_pos[w[i]] = i;
    }
    for (int i = 1; i <= 2 * n; i++) {
        w[i + 1] = (w[i] + a[i + n]) % m;
        t[w[i + 1]]++;
        if (i >= n) {
            an += t[w[i]];
            t[w_pos[w[i]]]--;
            t[w[i]]--;
        }
    }
    cout << an;
    return 0;
}