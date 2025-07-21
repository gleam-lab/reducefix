#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 10;
vector<int> vec[MAXN];
queue<int> q;
bool vis[MAXN];
int step[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, u, v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u); // Assuming the graph is undirected
    }

    q.push(1);
    vis[1] = true;
    step[1] = 0;

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int to : vec[top]) {
            if (!vis[to]) {
                vis[to] = true;
                step[to] = step[top] + 1;
                q.push(to);
            }
        }
    }

    bool found = false;
    for (int i = 2; i <= n; i++) {
        if (step[i] != INF) {
            cout << step[i] << " ";
            found = true;
        } else {
            cout << "-1 ";
        }
    }

    if (!found) {
        cout << "-1";
    }

    return 0;
}