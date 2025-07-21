#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int n, q;
vector<int> a, b;
vector<long long> pre_sum;

long long query(int idx) {
    if (idx == 0) return 0;
    return pre_sum[idx] - pre_sum[idx - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    a.resize(n + 1);
    b.resize(q + 1);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre_sum.push_back(pre_sum.back() + abs(a[i]));
    }

    for (int i = 1; i <= q; ++i) {
        cin >> b[i];
    }

    sort(b.begin(), b.end());

    for (int i = 1; i <= q; ++i) {
        int pos = lower_bound(b.begin(), b.end(), b[i]) - b.begin();
        cout << query(pos) << '\n';
    }

    return 0;
}