#include <bits/stdc++.h>
using namespace std;

bool canStore(int x, vector<int>& va, vector<int>& vb) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto& b : vb) pq.push(b);
    
    for(auto& a : va) {
        while(!pq.empty() && pq.top() < a) pq.pop();
        if(pq.empty()) return false;
        pq.pop();
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n-1);
    for(int i=0; i<n; ++i) cin >> va[i];
    for(int i=0; i<n-1; ++i) cin >> vb[i];
    
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    
    int l = 0, r = 1e9 + 10, ans = -1;
    while(l <= r) {
        int m = (l + r) / 2;
        if(canStore(m, va, vb)) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    
    cout << ans << '\n';
    return 0;
}