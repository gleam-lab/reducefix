#include <bits/stdc++.h>

using namespace std;

vector<int> A, B, dist;
vector<long long> tree;

long long query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) update(node * 2, start, mid, idx, val);
        else update(node * 2 + 1, mid + 1, end, idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

int find_kth_smallest(int k) {
    int left = 0, right = 2e8, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (query(1, 0, 2e8, 0, mid) >= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    A.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    B.resize(q);
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> B[i] >> queries[i].second;
        queries[i].first = i;
    }

    sort(A.begin(), A.end());
    dist.assign(n, 0);

    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        dist[pos] = abs(B[i] - A[pos]);
        if (pos > 0) dist[pos] = min(dist[pos], abs(B[i] - A[pos - 1]));
        if (pos + 1 < n) dist[pos] = min(dist[pos], abs(B[i] - A[pos + 1]));
    }

    tree.assign(4 * 2e8, 0);
    for (int i = 0; i < n; ++i) {
        update(1, 0, 2e8, dist[i], 1);
    }

    sort(queries.begin(), queries.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return queries[a.first].second < queries[b.first].second;
    });

    int last_k = 0;
    for (auto& [id, k] : queries) {
        while (last_k < k) {
            int next = find_kth_smallest(last_k + 1);
            update(1, 0, 2e8, next, 0);
            dist.erase(find(dist.begin(), dist.end(), next));
            last_k++;
        }
        cout << last_k << '\n';
    }

    return 0;
}