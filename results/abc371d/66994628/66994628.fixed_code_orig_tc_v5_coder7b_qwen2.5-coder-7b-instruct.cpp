#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n;
    vector<int> x(n + 1), p(n + 1);
    for(int i = 1; i <= n; ++i) cin >> x[i];
    for(int i = 1; i <= n; ++i) cin >> p[i];

    vector<long long> prefix_sum(n + 1);
    for(int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }

    cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        cout << prefix_sum[r] - prefix_sum[l - 1] << '\n';
    }
    return 0;
}