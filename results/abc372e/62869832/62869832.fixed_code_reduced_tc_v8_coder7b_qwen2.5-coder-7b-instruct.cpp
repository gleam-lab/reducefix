#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int parent[MAXN], bit[MAXN];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    parent[y] = x;
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void update(int idx, int val) {
    while (idx < MAXN) {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}

int kthLargest(int n, vector<int> &freq) {
    for (int i = 1; i <= n; ++i) freq[i] = query(i);
    sort(freq.begin() + 1, freq.end());
    reverse(freq.begin() + 1, freq.end());
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (freq[i] == 0) break;
        count++;
        if (count == freq.size()) return i;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        update(i, 1);
    }

    vector<int> freq(n + 1, 0);
    freq[1] = 1;

    while (q--) {
        int type, u, v, k;
        cin >> type;
        if (type == 1) {
            cin >> u >> v;
            if (find(u) != find(v)) {
                unionSets(u, v);
                freq[find(u)] += freq[find(v)];
                freq[find(v)] = 0;
                update(find(u), 1);
                update(find(v), -1);
            }
        } else {
            cin >> u >> k;
            cout << kthLargest(n, freq) << "\n";
        }
    }

    return 0;
}