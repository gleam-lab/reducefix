#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct edge {
    int to;
} a[200001];

int n, m;
vector<int> adjList[200001];
int ans[200001] = {100000000};

void dfs(int u) {
    for (int &v : adjList[u]) {
        if (ans[v] == 100000000) {
            ans[v] = ans[u] + 1;
            dfs(v);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        adjList[u].push_back(v);
    }
    dfs(1);
    cout << (ans[1] == 100000000 ? "-1" : to_string(ans[1]));
    return 0;
}