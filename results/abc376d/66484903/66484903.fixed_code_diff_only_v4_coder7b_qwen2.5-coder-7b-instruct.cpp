#include<bits/stdc++.h>
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
    for (ll i = 0; i < m; i++) { // Corrected loop index from 1 to 0
        scanf("%lld %lld", &u, &v);
        vec[u].push_back(v);
    }
    q.push(1);
    step[1] = 0; // Initialize starting point distance as 0
    while (!q.empty()) {
        ll top = q.front();
        vis[top] = true;
        q.pop();
        for (ll i = 0; i < vec[top].size(); i++) {
            ll to = vec[top][i];
            if (!vis[to]) {
                step[to] = step[top] + 1;
                q.push(to);
            }
        }
    }
    if (step[n] == INF) { // Check if destination is unreachable
        printf("-1");
    } else {
        printf("%lld", step[n]);
    }
    return 0;
}