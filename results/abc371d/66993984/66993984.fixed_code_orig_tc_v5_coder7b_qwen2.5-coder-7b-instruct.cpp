#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;

int n, q;
vector<int> x(MAXN), p(MAXN);
vector<long long> prefix_sum(MAXN);

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> x[i];
    for(int i = 1; i <= n; ++i) cin >> p[i];
    prefix_sum[0] = 0;
    for(int i = 1; i <= n; ++i) prefix_sum[i] = prefix_sum[i - 1] + p[i];

    cin >> q;
    while(q--) {
        int L, R;
        cin >> L >> R;
        int c = lower_bound(x.begin(), x.end(), L) - x.begin();
        int d = upper_bound(x.begin(), x.end(), R) - x.begin();
        cout << prefix_sum[d - 1] - prefix_sum[c - 1] << '\n';
    }
    return 0;
}