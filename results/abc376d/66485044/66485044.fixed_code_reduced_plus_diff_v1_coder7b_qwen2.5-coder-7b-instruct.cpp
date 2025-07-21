#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 10;

vector<int> vec[MAXN];
queue<int> q;
int step[MAXN];
bool vis[MAXN];

int main() {
    ll n, m, u, v;
    scanf("%lld %lld", &n, &m);
    
    // Build the adjacency list
    for (ll i = 1; i <= m; i++) {
        scanf("%lld %lld", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u); // Since the graph is undirected
    }

    // Initialize the queue with the starting node (1)
    q.push(1);
    vis[1] = true;
    step[1] = 0;

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for (int i = 0; i < vec[top].size(); i++) {
            int to = vec[top][i];
            if (!vis[to]) {
                step[to] = step[top] + 1;
                vis[to] = true;
                q.push(to);

                // If we reach node n, print the number of steps and exit
                if (to == n) {
                    printf("%lld\n", step[n]);
                    return 0;
                }
            }
        }
    }

    // If we exhaust the queue without reaching node n, there is no path
    printf("-1\n");
    return 0;
}