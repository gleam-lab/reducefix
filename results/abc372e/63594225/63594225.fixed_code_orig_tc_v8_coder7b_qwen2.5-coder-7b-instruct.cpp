#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const int MAXN = 2 * 100005;

struct UF {
    vector<int> parent, size;
    vector<priority_queue<int, vector<int>, greater<>>> pq;

    UF(int n) {
        parent.resize(n);
        size.resize(n, 1);
        pq.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;

        if (size[x] < size[y]) swap(x, y);
        size[x] += size[y];
        parent[y] = x;
        
        // Merge the priority queues
        while (!pq[y].empty()) {
            pq[x].push(pq[y].top());
            pq[y].pop();
        }
    }

    void addEdge(int x, int y) {
        merge(x, y);
        pq[find(x)].push(1);
    }

    int kthLargest(int x, int k) {
        x = find(x);
        if (pq[x].size() < k) return -1;
        auto it = pq[x].begin();
        advance(it, pq[x].size() - k);
        return *it;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    UF uf(n + 1);

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            uf.addEdge(u, v);
        } else {
            cout << uf.kthLargest(u, v) << '\n';
        }
    }

    return 0;
}