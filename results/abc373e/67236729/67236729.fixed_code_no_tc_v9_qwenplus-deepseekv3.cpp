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
    
    vector<i64> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    
    vector<i64> prefix_sum(N + 1);
    for (int i = 0; i < N; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }
    
    auto find_min_votes = [&](i64 target) -> i64 {
        int pos = upper_bound(sorted_A.begin(), sorted_A.end(), target) - sorted_A.begin();
        int cnt = N - pos;
        
        if (cnt < M) return 0; // Already meets condition
        
        i64 needed_sum = prefix_sum[N] - prefix_sum[pos] - prefix_sum[pos - (M - 1)] + prefix_sum[pos - M];
        i64 min_votes = max(needed_sum - (K - (prefix_sum[N] - target)), 0LL);
        
        if (min_votes + target > K) return -1;
        return min_votes;
    };
    
    for (int i = 0; i < N; i++) {
        i64 low = A[i], high = K;
        i64 answer = -1;
        
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 res = find_min_votes(mid);
            
            if (res != -1 && mid - A[i] >= res) {
                answer = mid - A[i];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << answer << " ";
    }
    
    cout << "\n";
    return 0;
}