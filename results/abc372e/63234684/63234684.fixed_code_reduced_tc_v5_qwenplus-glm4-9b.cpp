#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < n; i++)
#define all(x) (x).begin(), (x).end()
using P = pair<int, int>;
using T = tuple<int, int, int>; // (size, rank, root)

struct UnionFind {
    vector<T> uf;
    UnionFind(int n) : uf(n, {1, 0, i}) {}

    int root(int v) {
        if (get<2>(uf[v]) == v) return v;
        int root = root(get<2>(uf[v]));
        uf[v] = {get<0>(uf[v]), get<1>(uf[v]), root};
        return root;
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    void merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (get<0>(uf[x]) < get<0>(uf[y])) swap(x, y);
        uf[x] = {get<0>(uf[x]) + get<0>(uf[y]), min(get<1>(uf[x]), get<1>(uf[y])), y};
    }

    vector<int> kth_largest(int v, int k) {
        int root = root(v);
        int size = get<0>(uf[root]);
        if (k > size) return {-1};
        int current = root;
        vector<int> comp(size);
        for (int i = 0; i < size; i++) {
            current = root(get<2>(uf[current]));
            comp[i] = current;
        }
        sort(all(comp), [k](int a, int b) {
            return find(comp.begin(), comp.end(), a) < find(comp.begin(), comp.end(), b);
        });
        return {comp[size - k]};
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    UnionFind uf(n);
    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            uf.merge(a - 1, b - 1);
        } else {
            vector<int> result = uf.kth_largest(a - 1, b);
            if (result[0] == -1) {
                cout << -1 << endl;
            } else {
                cout << result[0] + 1 << endl;
            }
        }
    }
    return 0;
}