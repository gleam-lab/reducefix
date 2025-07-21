#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector<int> parent;
vector<priority_queue<int, vector<int>, greater<int>>> top_k;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (top_k[a].size() < top_k[b].size())
            swap(a, b);
        parent[b] = a;
        while (!top_k[b].empty()) {
            top_k[a].push(top_k[b].top());
            top_k[b].pop();
            if (top_k[a].size() > 10)
                top_k[a].pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    top_k.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        top_k[i].push(i);
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            union_sets(a, b);
        } else {
            a = find_set(a);
            if (top_k[a].size() < b) {
                cout << -1 << '\n';
            } else {
                vector<int> temp;
                while (!top_k[a].empty()) {
                    temp.push_back(top_k[a].top());
                    top_k[a].pop();
                }
                cout << temp[temp.size() - b] << '\n';
                for (int num : temp) {
                    top_k[a].push(num);
                }
            }
        }
    }

    return 0;
}