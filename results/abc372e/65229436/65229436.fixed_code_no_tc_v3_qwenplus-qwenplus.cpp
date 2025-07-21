#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0;i<(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using ll = long long;
using pi = pair<int, int>;
const int di[]={1,-1,0,0};
const int dj[]={0,0,1,-1};
const int INF=1e9;

struct UnionFind {
    vector<int> parent;
    vector<vector<int>> components;

    UnionFind(int n) : parent(n), components(n) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            components[i].push_back(i);
        }
    }

    int findRoot(int x) {
        if (parent[x] != x)
            parent[x] = findRoot(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = findRoot(x), ry = findRoot(y);
        if (rx == ry) return false;

        // Always merge smaller into larger
        if (components[rx].size() < components[ry].size())
            swap(rx, ry);

        // Merge ry's elements into rx's component
        components[rx].insert(components[rx].end(),
                              make_move_iterator(components[ry].begin()),
                              make_move_iterator(components[ry].end()));
        components[ry].clear();

        parent[ry] = rx;
        return true;
    }

    const vector<int>& getComponent(int x) {
        return components[findRoot(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    vector<int> ans;

    rep(qi, q) {
        int com;
        cin >> com;
        if(com == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            uf.unite(u, v);
        } else if (com == 2) {
            int v, k;
            cin >> v >> k;
            v--;
            const auto& comp = uf.getComponent(v);
            if ((int)comp.size() < k) {
                ans.push_back(-1);
            } else {
                // Sort the component in descending order and pick k-th
                // But we can optimize by maintaining a sorted structure
                // For small k (up to 10), we can find top-k largest using partial sort
                vector<int> top_k = comp;
                nth_element(top_k.begin(), top_k.begin() + k - 1, top_k.end(), greater<int>());
                int kth_largest = top_k[k - 1];
                ans.push_back(kth_largest + 1); // Convert back to 1-based index
            }
        }
    }

    for(auto x: ans)
        cout << x << endl;

    return 0;
}