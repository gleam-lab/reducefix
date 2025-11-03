#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Sort the A points for binary search
    sort(a.begin(), a.end());
    
    for (int i = 0; i < q; i++) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Find the position where b would be inserted
        auto it = lower_bound(a.begin(), a.end(), b);
        int pos = it - a.begin();
        
        // We'll consider points around position pos
        // The k-th closest point must be within k positions to the left or right
        int left = max(0, pos - k);
        int right = min(n - 1, pos + k - 1);
        
        // Extract the relevant segment
        vector<ll> distances;
        for (int j = left; j <= right; j++) {
            distances.push_back(abs(a[j] - b));
        }
        
        // Sort distances and get the k-th smallest
        sort(distances.begin(), distances.end());
        cout << distances[k - 1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}