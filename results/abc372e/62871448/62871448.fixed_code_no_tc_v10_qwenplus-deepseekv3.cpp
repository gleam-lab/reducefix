#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> as[MAXN];
int fa[MAXN];

int gtf(int x) {
    if (x == fa[x]) return x;
    return fa[x] = gtf(fa[x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        fa[i] = i;
        as[i].push_back(i);
    }

    while (Q--) {
        int op, u, v;
        cin >> op >> u >> v;

        if (op == 1) {
            int root_u = gtf(u);
            int root_v = gtf(v);
            if (root_u != root_v) {
                if (as[root_u].size() < as[root_v].size()) {
                    swap(root_u, root_v);
                }
                // Merge the smaller list into the larger one
                for (int num : as[root_v]) {
                    as[root_u].push_back(num);
                }
                // Sort in descending order and keep only top 10
                sort(as[root_u].rbegin(), as[root_u].rend());
                if (as[root_u].size() > 10) {
                    as[root_u].resize(10);
                }
                fa[root_v] = root_u;
            }
        } else {
            int root = gtf(u);
            if (v > as[root].size()) {
                cout << -1 << '\n';
            } else {
                cout << as[root][v - 1] << '\n';
            }
        }
    }

    return 0;
}