#include <bits/stdc++.h>
using namespace std;

vector<int> a;

void preprocess() {
    sort(a.begin(), a.end());
    for (size_t i = 1; i < a.size(); ++i) {
        a[i] += a[i - 1];
    }
}

int query(int x, int k) {
    auto it = lower_bound(a.begin(), a.end(), x);
    if (it == a.end()) return INT_MAX;
    int idx = it - a.begin();
    return idx < k ? INT_MAX : a[idx] - (idx - k >= 0 ? a[idx - k] : 0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q; cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    preprocess();

    for (int i = 0; i < q; ++i) {
        int b, k; cin >> b >> k;
        cout << query(abs(b), k) << '\n';
    }

    return 0;
}