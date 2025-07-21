#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M, K;
    cin >> N >> M >> K;
    vector<i64> A(N);
    for (auto& a : A) cin >> a;
    
    if (N == 1) {
        cout << "0\n";
        return 0;
    }
    
    vector<i64> B = A;
    sort(B.begin(), B.end());
    
    vector<i64> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + B[i];
    }
    
    i64 total = prefix[N];
    i64 remaining = K - total;
    
    for (i64 x : A) {
        // Find how many elements are > x + d in original array
        // We want at most M-1 elements to be > x + d
        // Binary search for minimal d
        
        i64 low = 0, high = remaining;
        i64 ans = -1;
        
        while (low <= high) {
            i64 mid = (low + high) / 2;
            
            // Count how many would be > x + mid after distribution
            i64 threshold = x + mid;
            auto it = upper_bound(B.begin(), B.end(), threshold);
            i64 cnt = B.end() - it;
            
            if (cnt < M) {
                // Need to make sure we can't have M or more > x + mid
                // The worst case is when other candidates get as many votes as possible
                // The sum of votes distributed to make others > threshold
                i64 needed = 0;
                if (cnt > 0) {
                    i64 start_pos = it - B.begin();
                    i64 end_pos = min(N, start_pos + (M - 1 - cnt));
                    if (end_pos > start_pos) {
                        needed = (threshold + 1) * (end_pos - start_pos) - 
                                (prefix[end_pos] - prefix[start_pos]);
                    }
                }
                
                if (needed <= remaining - mid) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }
        
        cout << ans << " ";
    }
    cout << "\n";
    
    return 0;
}