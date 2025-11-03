#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    // Sort the A points for binary search and distance calculation
    sort(a.begin(), a.end());
    
    for (int j = 0; j < Q; j++) {
        int b, k;
        cin >> b >> k;
        
        // Binary search on the answer (distance)
        int left = 0, right = 2e8;
        int ans = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Count how many points in A are within distance 'mid' from B_j
            int low_bound = lower_bound(a.begin(), a.end(), b - mid) - a.begin();
            int high_bound = upper_bound(a.begin(), a.end(), b + mid) - a.begin();
            int count = high_bound - low_bound;
            
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}