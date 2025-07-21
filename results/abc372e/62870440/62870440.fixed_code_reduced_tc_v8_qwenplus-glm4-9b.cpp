#include<bits/stdc++.h>
using namespace std;

int n, q;
int parent[200005];
int rank[200005];
int size[200005];
int as[200005][60];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            rank[rootX]++;
        }

        // Merge the k-th largest arrays
        for (int i = 1; i < 20; ++i) {
            if (as[rootX][i] != -1 && as[rootY][i] != -1) {
                vector<int> temp;
                for (int j = 0; j < size[rootX]; ++j) {
                    temp.push_back(as[rootX][i]);
                }
                for (int j = 0; j < size[rootY]; ++j) {
                    temp.push_back(as[rootY][i]);
                }
                sort(temp.begin(), temp.end(), greater<int>());
                for (int j = 0; j < 10; ++j) {
                    as[rootX][i] = temp[j];
                }
                break;
            }
        }
    }
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 0;
        size[i] = 1;
        fill_n(as[i], 60, -1);
    }

    int op, u, v;
    for (int i = 0; i < q; ++i) {
        cin >> op >> u >> v;

        if (op == 1) {
            union_sets(u, v);
        } else if (op == 2) {
            int rootV = find(v);
            if (as[rootV][k - 1] != -1) {
                cout << as[rootV][k - 1] << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}