#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const int MAXN = 2 * 100005;

class UnionFind {
public:
    vector<int> parent, rank, degree;

    UnionFind(int n) : parent(n), rank(n, 1), degree(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (rank[x] > rank[y]) {
                swap(x, y);
            }
            parent[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
            degree[y] += degree[x] + 1;
            pq[y].insert(degree[y]);
            pq[x].erase(degree[x]);
        }
    }

    int getKthLargest(int x, int k) {
        x = find(x);
        if (pq[x].size() < k) {
            return -1;
        } else {
            auto it = pq[x].rbegin();
            advance(it, k - 1);
            return *it;
        }
    }

private:
    unordered_map<int, multiset<int>> pq;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    UnionFind uf(n);

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            uf.unite(a - 1, b - 1);
        } else {
            int result = uf.getKthLargest(a - 1, b);
            cout << result << '\n';
        }
    }

    return 0;
}