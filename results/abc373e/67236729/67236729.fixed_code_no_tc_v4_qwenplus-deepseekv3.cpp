#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    i64 K;
    cin >> N >> M >> K;
    
    vector<i64> A(N);
    for (auto &a : A) cin >> a;
    
    vector<i64> sorted = A;
    sort(sorted.begin(), sorted.end());
    
    vector<i64> prefix(N + 1);
    for (int i = 0; i < N; i++) {
        prefix[i+1] = prefix[i] + sorted[i];
    }
    
    for (int i = 0; i < N; i++) {
        i64 target = A[i];
        
        // Find the position in sorted array
        auto it = upper_bound(sorted.begin(), sorted.end(), target);
        int pos = it - sorted.begin();
        
        // Binary search for the minimum X
        i64 low = 0, high = K, ans = -1;
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_val = target + mid;
            
            // Find how many are >= new_val
            it = upper_bound(sorted.begin(), sorted.end(), new_val);
            int cnt = sorted.end() - it;
            
            if (cnt < M) {
                // Need to make sure at most M-1 candidates have > new_val
                // Calculate the sum needed to make others <= new_val
                i64 sum_needed = 0;
                if (cnt > 0) {
                    int start = N - cnt;
                    sum_needed = prefix[N] - prefix[start] - new_val * cnt;
                }
                
                // Check if remaining votes can satisfy this
                if (sum_needed <= (K - mid)) {
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
    
    return 0;
}