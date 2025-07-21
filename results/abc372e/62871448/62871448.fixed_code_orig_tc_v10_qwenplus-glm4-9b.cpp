#include <bits/stdc++.h>
using namespace std;
vector<int> parent, size, list_of_vertices;
int n, q;

int find(int a) {
    if (a == parent[a]) return a;
    parent[a] = find(parent[a]);
    return parent[a];
}

void union_vertices(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        merge(list_of_vertices[a], list_of_vertices[b]);
    }
}

void merge(vector<int>& a, vector<int>& b) {
    for (int elem : b) {
        sort(a.rbegin(), a.rend());
        a.push_back(elem);
    }
}

int main() {
    cin >> n >> q;
    parent.resize(n + 1);
    size.resize(n + 1);
    list_of_vertices.resize(n + 1);
    iota(parent.begin(), parent.end(), 1);
    fill(size.begin(), size.end(), 1);

    for (int i = 0; i < q; i++) {
        int op, u, v, k;
        cin >> op >> u >> v;
        if (op == 1) {
            union_vertices(u, v);
        } else {
            k = cin >> k;
            int root = find(v);
            if (list_of_vertices[root].size() < k) cout << -1 << endl;
            else cout << list_of_vertices[root][k - 1] << endl;
        }
    }

    return 0;
}