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
    
    vector<i64> B = A;
    sort(B.begin(), B.end());
    
    vector<i64> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i+1] = prefix[i] + B[i];
    }
    
    for (int i = 0; i < N; ++i) {
        i64 a = A[i];
        i64 low = 0, high = K, ans = -1;
        
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_a = a + mid;
            
            // Find how many elements are > new_a
            int pos = upper_bound(B.begin(), B.end(), new_a) - B.begin();
            int cnt_greater = N - pos;
            
            if (cnt_greater < M) {
                // Already meets the condition
                ans = mid;
                high = mid - 1;
                continue;
            }
            
            // Need to make sure at most M-1 candidates have more votes
            // Calculate the minimal sum needed to make M-1 candidates > new_a
            int needed = M - 1 - cnt_greater;
            if (needed >= 0) {
                // This case shouldn't happen since cnt_greater >= M
                low = mid + 1;
                continue;
            }
            
            // The candidates from pos to pos+(-needed-1) need to be boosted to > new_a
            int start = pos + needed;
            if (start < 0) start = 0;
            
            i64 required = (new_a + 1) * (-needed) - (prefix[pos] - prefix[start]);
            
            if (required <= K - mid) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << ans << " ";
    }
    
    cout << "\n";
    return 0;
}