#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    while (Q--) {
        int b, k;
        cin >> b >> k;
        
        // Binary search on the answer (distance)
        int left = 0, right = 2e16; // Sufficiently large upper bound
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from point b
            int left_bound = b - mid;
            int right_bound = b + mid;
            
            auto it1 = lower_bound(a.begin(), a.end(), left_bound);
            auto it2 = upper_bound(a.begin(), a.end(), right_bound);
            
            int count = it2 - it1;
            
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << '\n';
    }
    
    return 0;
}