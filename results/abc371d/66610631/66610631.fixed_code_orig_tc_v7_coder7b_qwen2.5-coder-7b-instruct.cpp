#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

vector<ll> prefix_sums;

void preprocess(vector<int>& a, int n) {
    prefix_sums.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sums[i] = prefix_sums[i - 1] + a[i];
    }
}

ll query(int l, int r) {
    return prefix_sums[r] - prefix_sums[l - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    preprocess(a, n);

    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }

    return 0;
}