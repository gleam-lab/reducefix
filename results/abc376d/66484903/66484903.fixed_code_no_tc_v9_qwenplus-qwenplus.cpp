#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;

vector<ll> vec[MAXN];
queue<ll> q;
ll step[MAXN];
bool vis[MAXN];

int main() {
    ll n, m, u, v;
    scanf("%lld %lld", &n, &m);
    
    for (ll i = 1; i <= m; ++i) {
        scanf("%lld %lld", &u, &v);
        vec[u].push_back(v);
    }

    // Initialize BFS from node 1
    memset(step, INF, sizeof(step));
    step[1] = 0;
    vis[1] = true;
    q.push(1);

    while (!q.empty()) {
        ll top = q.front();
        q.pop();

        for (ll to : vec[top]) {
            if (!vis[to]) {
                step[to] = step[top] + 1;
                vis[to] = true;
                q.push(to);
            }
        }
    }

    // Output shortest distance to node n
    if (step[n] == INF) {
        printf("-1\n");
    } else {
        printf("%lld\n", step[n]);
    }

    return 0;
}