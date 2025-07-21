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
    
    if (v[a].size() < v[b].size()) swap(a, b);
    
    while (!v[b].empty()) {
        v[a].push(v[b].top());
        v[b].pop();
        if (v[a].size() > 10) v[a].pop();
    }
    
    p[b] = a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    p.resize(n+1);
    v.resize(n+1);
    
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
                cout << -1 << '\n';
            } else {
                vector<int> temp;
                while (!v[a].empty()) {
                    temp.push_back(v[a].top());
                    v[a].pop();
                }
                cout << temp[temp.size() - b] << '\n';
                for (int x : temp) {
                    v[a].push(x);
                }
            }
        }
    }
    
    return 0;
}