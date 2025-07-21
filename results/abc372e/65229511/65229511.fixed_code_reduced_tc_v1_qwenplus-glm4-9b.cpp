#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_N = 200000;
vector<int> parent(MAX_N + 1);
vector<int> rank(MAX_N + 1);

void init(int n) {
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    init(n);

    vector<set<int>> components(n + 1);
    for (int i = 1; i <= n; ++i) {
        components[find(i)].insert(i);
    }

    vector<int> answers;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
            components[v].insert(u);
        } else if (type == 2) {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            int size = components[root].size();
            if (k > size) {
                answers.push_back(-1);
            } else {
                auto it = components[root].rbegin();
                std::advance(it, k - 1);
                answers.push_back(*it);
            }
        }
    }

    for (int answer : answers) {
        cout << answer << endl;
    }

    return 0;
}