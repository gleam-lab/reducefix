#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10;
vector<int> vec[MAXN]; // Changed from vector<ll> to vector<int> as node indices are integers
queue<int> q; // Changed from queue<ll> to queue<int> as node indices are integers
int step[MAXN];
bool vis[MAXN];

int main() {
    int n, m, u, v;
    scanf("%d %d", &n, &m); // Changed from ll to int as n and m are typically small numbers
    for (int i = 0; i < m; i++) { // Changed from ll to int as loop index is an integer
        scanf("%d %d", &u, &v); // Changed from ll to int as node indices are integers
        vec[u].push_back(v);
    }
    q.push(1);
    step[1] = 0; // Initialize step for starting node
    while (!q.empty()) {
        int top = q.front();
        vis[top] = true;
        q.pop();
        for (int i = 0; i < vec[top].size(); i++) {
            int to = vec[top][i];
            if (to == 1) {
                printf("%d\n", step[top] + 1); // Print result directly without returning early
                return 0;
            }
            if (!vis[to]) {
                step[to] = step[top] + 1;
                q.push(to);
            }
        }
    }
    printf("-1\n"); // Print -1 after all nodes are processed
    return 0;
}