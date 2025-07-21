#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 200005;
int n, m, mn = INT_MAX, vis[N];
vector<int> b[N];

void dfs(int x, int cnt) {
    if (vis[x]) return; // Avoid revisiting nodes
    vis[x] = 1;
    for (int i = 0; i < b[x].size(); i++) {
        int v = b[x][i];
        if (!vis[v]) {
            dfs(v, cnt + 1); // Increment count only when visiting a new node
        } else if (v == 1) {
            mn = min(mn, cnt + 1); // Update minimum path length if reaching node 1
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        b[u].push_back(v);
    }
    dfs(1, 0);
    if (mn == INT_MAX) {
        cout << -1;
    } else {
        cout << mn;
    }
    return 0;
}