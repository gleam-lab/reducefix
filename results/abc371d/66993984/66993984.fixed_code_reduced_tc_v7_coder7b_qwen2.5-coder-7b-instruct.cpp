#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, q, x[MAXN], p[MAXN];
long long sum[MAXN];

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i];
    }
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int c = lower_bound(x + 1, x + n + 1, l) - x;
        int d = upper_bound(x + 1, x + n + 1, r) - x;
        if(c == 0 && x[1] > l) --c;
        if(d == n + 1 || x[n] < r) ++d;
        cout << sum[d-1] - sum[c-1] << endl;
    }
    return 0;
}