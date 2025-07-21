#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> g[N], rev_g[N];
int n, m, dep[N], rev_dep[N];

int bfs(int start, int *dep_arr) {
    queue<int> q;
    q.push(start);
    dep_arr[start] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : (start == 1 ? g : rev_g)[u]) {
            if (dep_arr[v])
                return dep_arr[u];
            dep_arr[v] = dep_arr[u] + 1;
            q.push(v);
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        rev_g[v].push_back(u);
    }

    int result = bfs(1, dep);
    if (result == -1 && bfs(n, rev_dep) == -1)
        result = 0;
    else
        result++;

    cout << result << '\n';
    return 0;
}