#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<long long> x(n + 1), p(n + 1);
    for(int i = 1; i <= n; ++i) cin >> x[i];
    for(int i = 1; i <= n; ++i) cin >> p[i];
    
    vector<long long> prefix_sum(n + 1);
    prefix_sum[1] = p[1];
    for(int i = 2; i <= n; ++i) prefix_sum[i] = prefix_sum[i - 1] + p[i];

    while(q--) {
        int L, R;
        cin >> L >> R;
        long long result = prefix_sum[R] - (L > 1 ? prefix_sum[L - 1] : 0);
        cout << result << '\n';
    }
    return 0;
}