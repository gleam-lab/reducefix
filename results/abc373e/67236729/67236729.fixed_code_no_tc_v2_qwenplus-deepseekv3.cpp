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
    for (auto &a : A) {
        cin >> a;
        K -= a;
    }
    
    vector<i64> B = A;
    sort(B.begin(), B.end());
    
    vector<i64> prefix(N + 1);
    for (int i = 0; i < N; i++) {
        prefix[i+1] = prefix[i] + B[i];
    }
    
    for (int i = 0; i < N; i++) {
        i64 a = A[i];
        i64 low = 0, high = K;
        i64 ans = -1;
        
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_a = a + mid;
            
            // Find how many are greater than new_a
            int pos = upper_bound(B.begin(), B.end(), new_a) - B.begin();
            int cnt_greater = N - pos;
            
            if (cnt_greater < M) {
                ans = mid;
                high = mid - 1;
                continue;
            }
            
            // Need to ensure at most M-1 candidates have > new_a votes
            
            // Find first M candidates that would be > new_a
            int start = N - M;
            i64 sum = prefix[N] - prefix[start];
            
            if (B[start] <= new_a) {
                // Not enough candidates > new_a
                ans = mid;
                high = mid - 1;
            } else {
                i64 needed = 0;
                // Calculate how much we need to reduce the sum
                if (start > 0) {
                    needed = (B[start] - new_a) * M;
                }
                
                if (needed <= (K - mid)) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        
        cout << ans << " ";
    }
    
    cout << "\n";
    return 0;
}