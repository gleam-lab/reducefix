#include <bits/stdc++.h>
using namespace std;

const int MAX = 400005;
int n, m, a[MAX * 2];
long long prefix[400005 * 2], tree[400005 * 8];

void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        tree[node] += val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid)
        update(node * 2, l, mid, idx, val);
    else
        update(node * 2 + 1, mid + 1, r, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
        return 0;
    if (ql <= l && r <= qr)
        return tree[node];
    int mid = (l + r) / 2;
    return query(node * 2, l, mid, ql, qr) + query(node * 2 + 1, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i]; // duplicate for circular array
    }

    // Compute prefix sums mod m
    prefix[0] = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
    }

    // Coordinate compression for prefix values
    vector<long long> sorted;
    for (int i = 0; i <= 2 * n; ++i) {
        sorted.push_back(prefix[i]);
    }
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    auto getIdx = [&](long long x) {
        return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
    };

    // We need to find number of pairs (i,j) where i < j and (prefix[j] - prefix[i]) % m >= 0
    // This can be rephrased using prefix sum properties and sorted prefix sums
    long long result = 0;

    // Fenwick Tree implementation
    int size = sorted.size() + 2;

    for (int i = 0; i <= 2 * n; ++i) {
        int idx = getIdx(prefix[i]) + 1;
        result += query(1, 1, size, 1, idx);
        update(1, 1, size, idx, 1);
    }

    cout << result << endl;
    return 0;
}