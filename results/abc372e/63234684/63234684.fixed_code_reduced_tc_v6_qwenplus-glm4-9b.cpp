#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < n; i++)
using P = pair<int, int>;
using T = tuple<int, int, int>;

struct Union_Find {
    vector<int> parent, size, value;
    vector<vector<int>> component;

    Union_Find(int n) {
        parent.resize(n);
        size.resize(n, 1);
        value.resize(n, -1); // -1 indicates unused vertices
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find_set(int x) {
        if (parent[x] != x) {
            parent[x] = find_set(parent[x]);
        }
        return parent[x];
    }

    void union_set(int x, int y) {
        int rootX = find_set(x);
        int rootY = find_set(y);

        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) swap(rootX, rootY);
            parent[rootY] = rootX;
            size[rootX] += size[rootY];

            // Merge component lists
            component[rootX].insert(end(component[rootX]), begin(component[rootY]), end(component[rootY]));
            component[rootX].sort(rbegin(component[rootX]), rend(component[rootX]), greater<int>());
            
            // Remove duplicates and limit the size to 10
            component[rootX].erase(unique(rbegin(component[rootX]), rend(component[rootX])), rend(component[rootX]));
            if (component[rootX].size() > 10) component[rootX].erase(rbegin(component[rootX]) + 10, rend(component[rootX]));
        }
    }

    void add(int x) {
        int root = find_set(x);
        component[root].push_back(x);
        component[root].sort(rbegin(component[root]), rend(component[root]), greater<int>());
        component[root].erase(unique(rbegin(component[root]), rend(component[root])), rend(component[root]));
        if (component[root].size() > 10) component[root].erase(rbegin(component[root]) + 10, rend(component[root]));
    }

    vector<int> get_component(int x) {
        return component[find_set(x)];
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    Union_Find uf(n);
    vector<int> results;

    for (int i = 0; i < n; i++) {
        uf.add(i + 1); // Start indexing vertices from 1
    }

    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            uf.union_set(x, y);
        } else if (t == 2) {
            vector<int> component = uf.get_component(x);
            if (y > component.size()) {
                results.push_back(-1);
            } else {
                results.push_back(component[y - 1]);
            }
        }
    }

    for (auto res : results) {
        cout << res << endl;
    }

    return 0;
}