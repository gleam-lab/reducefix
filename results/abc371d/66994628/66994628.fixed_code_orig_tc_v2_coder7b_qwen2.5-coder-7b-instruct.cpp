#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
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
        if(l > r) swap(l, r);
        auto it_l = lower_bound(x + 1, x + n + 1, l);
        auto it_r = upper_bound(x + 1, x + n + 1, r);
        int idx_l = it_l - x, idx_r = it_r - x;
        if(idx_l == 1 && x[idx_l] < l) idx_l = 0;
        if(idx_r == n + 1 || x[idx_r] > r) --idx_r;
        cout << sum[idx_r] - sum[idx_l - 1] << '\n';
    }
    return 0;
}