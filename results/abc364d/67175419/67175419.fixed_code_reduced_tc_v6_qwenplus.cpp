#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    while (Q--) {
        long long b;
        int k;
        cin >> b >> k;
        
        // Binary search on the distance
        long long left = 0, right = 2e16;
        long long ans = right;
        
        while (left <= right) {
            long long mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from B
            auto lower = lower_bound(a.begin(), a.end(), b - mid);
            auto upper = upper_bound(a.begin(), a.end(), b + mid);
            int count = upper - lower;
            
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}