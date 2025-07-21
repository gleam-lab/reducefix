#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, q;
long long x[MAXN], p[MAXN];
vector<long long> prefix_sum;

void buildPrefixSum() {
    prefix_sum.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + p[i];
    }
}

long long query(int left, int right) {
    return prefix_sum[right] - prefix_sum[left - 1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    buildPrefixSum();

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }

    return 0;
}