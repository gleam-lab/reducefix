#include<bits/stdc++.h>
using namespace std;

int fa[200005];
vector<int> as[200005]; // Using vectors to dynamically store top elements
int n, q;

int gtf(int x) {
    if (fa[x] != x) {
        fa[x] = gtf(fa[x]);
    }
    return fa[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        as[i].push_back(i); // Initially, each vertex is its own component with itself as the only element
    }
    while (q--) {
        int op, u, v, k;
        cin >> op;
        if (op == 1) {
            cin >> u >> v;
            int fu = gtf(u);
            int fv = gtf(v);
            if (fu != fv) {
                // Merge the smaller set into the larger set to minimize merge operations
                if (as[fu].size() < as[fv].size()) {
                    swap(fu, fv);
                }
                // Merge fv into fu
                for (int num : as[fv]) {
                    as[fu].push_back(num);
                }
                // Sort in descending order and keep only top 10
                sort(as[fu].begin(), as[fu].end(), greater<int>());
                if (as[fu].size() > 10) {
                    as[fu].resize(10);
                }
                fa[fv] = fu;
            }
        } else {
            cin >> v >> k;
            int fv = gtf(v);
            if (as[fv].size() < k) {
                cout << -1 << "\n";
            } else {
                cout << as[fv][k - 1] << "\n";
            }
        }
    }
    return 0;
}