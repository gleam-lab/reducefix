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
        prefix[i + 1] = prefix[i] + B[i];
    }
    
    for (int i = 0; i < N; ++i) {
        i64 target = A[i];
        i64 low = 0, high = K;
        i64 ans = -1;
        
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_val = target + mid;
            
            // Find position where new_val would be inserted
            int pos = upper_bound(B.begin(), B.end(), new_val) - B.begin();
            int greater = N - pos;
            
            if (greater < M) {
                // Already enough
                ans = mid;
                high = mid - 1;
                continue;
            }
            
            // We need to make sure at least M-1 candidates have <= new_val
            // So we need to reduce the top M candidates to <= new_val
            
            int needed = greater - (M - 1);
            int start = pos - needed;
            if (start < 0) {
                // Not possible
                low = mid + 1;
                continue;
            }
            
            i64 sum = prefix[pos] - prefix[start];
            i64 required = new_val * needed - sum;
            i64 remaining = K - mid;
            
            if (required <= remaining) {
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