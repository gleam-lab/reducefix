#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct edge {
    int next, to;
} a[200001];

int n, m, head[200001], cnt, ans[200001];
bool in_queue[200001];

inline int read() {
    int res = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9') res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
    return res;
}

inline void add(int u, int v) {
    a[++cnt].next = head[u];
    a[cnt].to = v;
    head[u] = cnt;
}

void spfa() {
    queue<int> q;
    fill(ans, ans + n + 1, 100000000);
    ans[1] = 0;
    q.push(1);
    in_queue[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;

        for (int i = head[u]; i; i = a[i].next) {
            int v = a[i].to;
            if (ans[v] > ans[u] + 1) {
                ans[v] = ans[u] + 1;
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }
}

int main() {
    n = read(); m = read();
    for (int i = 1, u, v; i <= m; ++i) {
        u = read(); v = read();
        add(u, v);
    }

    spfa();

    if (ans[n] == 100000000)
        printf("-1");
    else
        printf("%d", ans[n]);
}