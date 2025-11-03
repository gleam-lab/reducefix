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
    
    // Sort the A points for binary search and two pointers
    sort(a.begin(), a.end());
    
    for (int i = 0; i < q; i++) {
        ll b;
        int k;
        cin >> b >> k;
        
        // Find the position where b would be inserted
        auto it = lower_bound(a.begin(), a.end(), b);
        int pos = it - a.begin();
        
        // We'll consider candidates from both left and right of b
        // Use two pointers to find k-th smallest distance
        int left = pos - 1;
        int right = pos;
        int count = 0;
        ll result = 0;
        
        // Expand outward from position until we find the k-th closest
        while (count < k) {
            // Check if we can take from left or right
            if (left >= 0 && (right >= n || b - a[left] <= a[right] - b)) {
                result = b - a[left];
                left--;
            } else if (right < n) {
                result = a[right] - b;
                right++;
            }
            count++;
        }
        
        cout << result << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solve();
    
    return 0;
}