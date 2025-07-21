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
    memset(step, 0x3f, sizeof(step)); // Set all steps to infinity initially
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
            
            // Early exit if we reach back to node 1 from a cycle
            if (to == 1 && top != 1) {
                printf("%lld\n", step[top] + 1);
                return 0;
            }
        }
    }

    // If no cycle found that includes node 1
    printf("-1\n");
    return 0;
}