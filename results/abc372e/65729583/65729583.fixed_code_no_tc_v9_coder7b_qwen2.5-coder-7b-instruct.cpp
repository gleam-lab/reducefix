#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int MAX_N = 200005;
const int MAX_Q = 200005;

int parent[MAX_N];
int rank[MAX_N];

void init(int n) {
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if(parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        if(rank[x] < rank[y]) {
            swap(x, y);
        }
        parent[y] = x;
        if(rank[x] == rank[y]) {
            rank[x]++;
        }
    }
}

vector<set<int>> adjacency_list(MAX_N);
vector<vector<int>> connected_components(MAX_N);

void update_connected_components() {
    for(int i = 1; i <= MAX_N; i++) {
        connected_components[find(i)].clear();
    }
    for(int i = 1; i <= MAX_N; i++) {
        connected_components[find(i)].insert(i);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    init(n);

    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int u, v;
            cin >> u >> v;
            unite(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            int root = find(v);
            if(connected_components[root].size() < k) {
                cout << -1 << endl;
            } else {
                auto it = connected_components[root].rbegin();
                advance(it, k-1);
                cout << *it << endl;
            }
        }
    }

    return 0;
}