#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<priority_queue<int, vector<int>, greater<int>>> v;
vector<int> p;

int par(int x) {
    if (p[x] == x) return x;
    return p[x] = par(p[x]);
}

void uni(int a, int b) {
    a = par(a), b = par(b);
    if (a == b) return;
    
    // Ensure 'a' is the smaller set to merge into 'b'
    if (v[a].size() > v[b].size()) swap(a, b);
    
    // Merge the smaller set into the larger one
    while (!v[a].empty()) {
        int val = v[a].top();
        v[a].pop();
        v[b].push(val);
        if (v[b].size() > 10) v[b].pop();
    }
    
    p[a] = b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    p.resize(n + 1);
    v.resize(n + 1);
    
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        v[i].push(i);
    }
    
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            uni(a, b);
        } else {
            a = par(a);
            if (v[a].size() < b) {
                cout << "-1\n";
            } else {
                // To get k-th largest, we need to access (size - k) element
                priority_queue<int> temp;
                while (!v[a].empty()) {
                    temp.push(v[a].top());
                    v[a].pop();
                }
                
                int res = -1;
                for (int i = 1; i <= b; i++) {
                    if (i == b) res = temp.top();
                    v[a].push(temp.top());
                    temp.pop();
                }
                while (!temp.empty()) {
                    v[a].push(temp.top());
                    temp.pop();
                }
                cout << res << '\n';
            }
        }
    }

    return 0;
}