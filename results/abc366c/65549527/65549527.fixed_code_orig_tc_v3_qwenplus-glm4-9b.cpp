#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int components;

public:
    UnionFind(int size) : parent(size), rank(size, 0), components(size) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX] += 1;
            }
            components--;
        }
    }

    int countComponents() const {
        return components;
    }
};

void solve() {
    int q;
    cin >> q;
    UnionFind uf(10^6 + 1); // Initialize union-find for 10^6 + 1 elements

    while (q--) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            uf.unionSets(0, x); // Union the set with element x
        } else if (a == 2) {
            int x;
            cin >> x;
            uf.unionSets(0, x); // Union the set with element x
        } else if (a == 3) {
            cout << uf.countComponents() << endl; // Count the number of components
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
   	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}