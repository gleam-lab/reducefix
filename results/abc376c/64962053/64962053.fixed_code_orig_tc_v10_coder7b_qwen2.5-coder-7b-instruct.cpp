#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& va, vector<int>& vb, int mid) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<va.size(); i++) {
        if(va[i] <= mid) pq.push(va[i]);
        else return false;
    }
    
    for(int i=1; i<vb.size(); i++) {
        while(!pq.empty() && pq.top() < vb[i]) pq.pop();
        if(pq.empty()) return false;
        pq.pop();
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n-1);
    for(int i=0; i<n; i++) cin >> va[i];
    for(int i=0; i<n-1; i++) cin >> vb[i];
    
    sort(va.rbegin(), va.rend());
    sort(vb.rbegin(), vb.rend());

    int l = 1, r = 1e9 + 10, ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(va, vb, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}