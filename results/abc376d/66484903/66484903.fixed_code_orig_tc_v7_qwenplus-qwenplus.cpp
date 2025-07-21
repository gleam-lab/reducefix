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
    memset(step, 0x3f, sizeof(step)); // Use INF as initial distance
    step[1] = 0;
    vis[1] = true;
    q.push(1);

    while (!q.empty()) {
        ll top = q.front();
        q.pop();

        for (ll to : vec[top]) {
            if (step[to] > step[top] + 1) {
                step[to] = step[top] + 1;
                q.push(to);
            }
        }
    }

    // If we reached node 1 again through a cycle, print the shortest cycle length
    if (step[1] != INF)
        printf("%lld\n", step[1]);
    else
        printf("-1\n");

    return 0;
}