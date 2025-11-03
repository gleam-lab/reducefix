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
    
    // Sort the A points for binary search and efficient queries
    sort(a.begin(), a.end());
    
    for (int j = 0; j < Q; j++) {
        int b, k;
        cin >> b >> k;
        
        // We'll use binary search on the answer (distance)
        int left = 0, right = 2e8;
        int ans = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Count how many points in A are within distance 'mid' from B
            int left_bound = b - mid;
            int right_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), left_bound);
            auto it2 = upper_bound(a.begin(), a.end(), right_bound);
            int count = it2 - it1;
            
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}