#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a)
        cin >> tt;
    for (auto &tt : b)
        cin >> tt;
    
    sort(a.rbegin(), a.rend()); // Sort toys in descending order
    sort(b.rbegin(), b.rend()); // Sort boxes in descending order
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n - 1; ++i)
        pq.push(b[i]); // Add all initial boxes to the priority queue
    
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int currToySize = a[i];
        while (!pq.empty() && pq.top() < currToySize)
            pq.pop(); // Remove boxes that are too small
        
        if (pq.empty()) {
            cout << "-1" << endl; // No suitable box found
            return;
        }
        
        int minBoxSize = pq.top();
        pq.pop();
        
        if (minBoxSize < ans)
            ans = minBoxSize;
        
        pq.push(minBoxSize); // Push back the used box for future toys
    }
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}