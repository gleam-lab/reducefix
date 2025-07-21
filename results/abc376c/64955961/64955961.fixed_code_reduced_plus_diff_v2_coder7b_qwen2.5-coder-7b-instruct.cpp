#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>& a, vector<int>& b, int x) {
    int m = a.size(), n = b.size();
    priority_queue<int, vector<int>, greater<>> pq;
    
    // Add initial boxes
    for(int i = 0; i < n; ++i) {
        pq.push(b[i]);
    }

    // Try to fit toys in boxes
    for(int i = 0; i < m; ++i) {
        if(pq.empty() || pq.top() < a[i]) return false;
        pq.pop();
        pq.push(max(x, a[i]));
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), b(n-1);

    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n-1; ++i) cin >> b[i];

    sort(begin(a), end(a));
    sort(begin(b), end(b));

    int l = 0, r = 1e9 + 10;
    while(l < r) {
        int mid = (l + r) / 2;
        if(check(a, b, mid)) r = mid;
        else l = mid + 1;
    }

    if(r == 1e9 + 10) cout << -1 << '\n';
    else cout << r << '\n';

    return 0;
}