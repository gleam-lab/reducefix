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
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    while (Q--) {
        int b, k;
        cin >> b >> k;
        
        // Binary search on the distance
        int left = 0, right = 200000000; // Maximum possible distance
        int result = right;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            // Count how many points in A are within distance 'mid' from b
            int left_bound = b - mid;
            int right_bound = b + mid;
            
            auto it1 = lower_bound(A.begin(), A.end(), left_bound);
            auto it2 = upper_bound(A.begin(), A.end(), right_bound);
            
            int count = it2 - it1;
            
            if (count >= k) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << result << '\n';
    }
    
    return 0;
}