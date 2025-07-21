#include "bits/stdc++.h"

using namespace std;

#define ff first
#define ss second
#define ll long long
#define SZ(s) (int)s.size()

int const N = 2e5 + 5;

vector<int> p;
vector<priority_queue<int, vector<int>, greater<int>>> tops;

int par(int x) {
    if(p[x] == x) return x;
    return p[x] = par(p[x]);
}

void uni(int a, int b) {
    a = par(a), b = par(b);
    if(a == b) return;
    
    if(tops[a].size() < tops[b].size()) swap(a, b);
    
    priority_queue<int> temp;
    while(!tops[b].empty()) {
        int val = tops[b].top();
        tops[b].pop();
        temp.push(val);
    }
    
    while(!temp.empty()) {
        int val = temp.top();
        temp.pop();
        tops[a].push(val);
        if(tops[a].size() > 10) tops[a].pop();
    }
    
    p[b] = a;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    p.resize(n+1);
    tops.resize(n+1);
    
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        tops[i].push(i);
    }
    
    while(q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) {
            uni(a, b);
        }
        else {
            a = par(a);
            if(tops[a].size() < b) {
                cout << -1 << '\n';
            }
            else {
                vector<int> temp;
                while(!tops[a].empty()) {
                    temp.push_back(tops[a].top());
                    tops[a].pop();
                }
                cout << temp[temp.size()-b] << '\n';
                for(int val : temp) tops[a].push(val);
            }
        }
    }

    return 0;
}