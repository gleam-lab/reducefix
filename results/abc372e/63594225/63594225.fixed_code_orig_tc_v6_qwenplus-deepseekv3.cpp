#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
vector<int> parent(N);
vector<int> size(N);
vector<priority_queue<int, vector<int>, greater<int>>> component(N);

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        
        // Merge the smaller priority queue into the larger one
        while (!component[b].empty()) {
            component[a].push(component[b].top());
            component[b].pop();
            if (component[a].size() > 10)
                component[a].pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
        component[i].push(i);
    }

    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            union_sets(u, v);
        } else {
            int root = find_set(u);
            if (component[root].size() < v) {
                cout << "-1\n";
            } else {
                // Need to get the v-th largest element
                stack<int> temp;
                while (component[root].size() > v) {
                    temp.push(component[root].top());
                    component[root].pop();
                }
                int ans = component[root].top();
                while (!temp.empty()) {
                    component[root].push(temp.top());
                    temp.pop();
                }
                cout << ans << '\n';
            }
        }
    }

    return 0;
}