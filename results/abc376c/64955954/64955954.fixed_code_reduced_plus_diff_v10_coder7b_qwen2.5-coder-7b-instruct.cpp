#include <bits/stdc++.h>
using namespace std;

bool canStore(vector<int>& va, vector<int>& vb, long long x) {
    priority_queue<int, vector<int>, greater<>> pq(va.begin(), va.end());
    for(int b : vb) {
        if(b >= x) continue;
        while(!pq.empty() && pq.top() < b) pq.pop();
        if(pq.empty()) return false;
        pq.pop();
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> va(n), vb(n-1);
    for(int i = 0; i < n; ++i) cin >> va[i];
    for(int i = 0; i < n-1; ++i) cin >> vb[i];

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    long long left = 0, right = 1e9 + 10, ans = -1;
    while(left <= right) {
        long long mid = (left + right) / 2;
        if(canStore(va, vb, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}