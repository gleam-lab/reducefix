#include <bits/stdc++.h>

using namespace std;

vector<int> p;
vector<vector<int>> top;

int par(int x) {
    if (p[x] == x) return x;
    return p[x] = par(p[x]);
}

void uni(int a, int b) {
    a = par(a), b = par(b);
    if (a == b) return;
    if (top[a].size() < top[b].size()) swap(a, b);
    vector<int> merged;
    int i = 0, j = 0;
    while (i < top[a].size() && j < top[b].size() && merged.size() < 10) {
        if (top[a][i] > top[b][j]) {
            merged.push_back(top[a][i]);
            i++;
        } else {
            merged.push_back(top[b][j]);
            j++;
        }
    }
    while (i < top[a].size() && merged.size() < 10) {
        merged.push_back(top[a][i]);
        i++;
    }
    while (j < top[b].size() && merged.size() < 10) {
        merged.push_back(top[b][j]);
        j++;
    }
    top[a] = merged;
    p[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    p.resize(n + 1);
    top.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        top[i].push_back(i);
    }
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            uni(a, b);
        } else {
            a = par(a);
            if (top[a].size() < b) {
                cout << -1 << '\n';
            } else {
                cout << top[a][b - 1] << '\n';
            }
        }
    }

    return 0;
}