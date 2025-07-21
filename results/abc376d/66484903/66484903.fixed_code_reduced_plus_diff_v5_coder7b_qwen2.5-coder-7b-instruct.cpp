#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
vector<int> vec[MAXN];
queue<int> q;
int step[MAXN];
bool vis[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, u, v;
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
    }

    q.push(1);
    vis[1] = true;
    step[1] = 0;

    while (!q.empty()) {
        int top = q.front();
        q.pop();

        for(int i = 0; i < vec[top].size(); i++) {
            int to = vec[top][i];
            if (!vis[to]) {
                step[to] = step[top] + 1;
                q.push(to);
                vis[to] = true;
            }
        }
    }

    bool found = false;
    for(int i = 1; i <= n; i++) {
        if(step[i] == 0 && i != 1) {
            printf("-%d\n", i);
            found = true;
            break;
        }
    }

    if(!found) {
        printf("1\n");
    }

    return 0;
}