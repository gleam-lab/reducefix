#include<bits/stdc++.h>
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
    
    int sum = 0;
    for (int i = 1; i < 2 * n; ++i) {
        sum = (sum + a[i]) % m;
        if (i > n) {
            an += t[(sum - a[i - n] + m) % m];
        }
        t[sum]++;
    }

    cout << an << endl;
    return 0;
}