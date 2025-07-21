#include <bits/stdc++.h>
using namespace std;

vector<long long> prefix_sum;

void build_prefix_sum(vector<int>& a) {
    prefix_sum.resize(a.size() + 1);
    for (int i = 1; i <= a.size(); ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }
}

long long query_range(int l, int r) {
    return prefix_sum[r] - prefix_sum[l - 1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    build_prefix_sum(b);

    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << query_range(l, r) << '\n';
    }

    return 0;
}