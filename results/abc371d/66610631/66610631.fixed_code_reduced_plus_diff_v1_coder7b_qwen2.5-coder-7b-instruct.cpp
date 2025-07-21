#include<bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e6 + 7;
vector<LL> prefix_sum(N, 0);

void build_prefix_sum(vector<int>& a) {
    for(int i = 1; i <= a.size(); ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }
}

LL query_range_sum(int l, int r) {
    return prefix_sum[r] - prefix_sum[l - 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    build_prefix_sum(b);
    
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        LL sum_l = query_range_sum(1, l);
        LL sum_r = query_range_sum(1, r);
        cout << sum_r - sum_l << '\n';
    }

    return 0;
}