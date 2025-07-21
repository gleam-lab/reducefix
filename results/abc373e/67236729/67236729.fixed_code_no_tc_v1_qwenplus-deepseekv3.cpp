#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 N, M, K;
    cin >> N >> M >> K;
    vector<i64> A(N);
    for (auto& a : A) cin >> a;
    
    vector<i64> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end(), greater<i64>());
    
    i64 remaining_votes = K - accumulate(A.begin(), A.end(), 0LL);
    
    for (i64 x : A) {
        i64 low = 0, high = remaining_votes, ans = -1;
        
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_x = x + mid;
            
            // Find how many candidates have >= new_x votes
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_x, greater<i64>());
            i64 count = distance(sorted_A.begin(), it);
            
            if (count < M) {
                // We need to ensure at most M-1 candidates have > new_x votes
                ans = mid;
                high = mid - 1;
            } else {
                // Need more votes to reduce the count
                low = mid + 1;
            }
        }
        
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}