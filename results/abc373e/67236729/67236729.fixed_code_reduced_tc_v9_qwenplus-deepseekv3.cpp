#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M, K;
    cin >> N >> M >> K;
    vector<i64> A(N);
    for (i64 &a : A) {
        cin >> a;
    }
    
    vector<i64> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    
    vector<i64> prefix(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    
    for (i64 a : A) {
        i64 low = 0, high = K;
        i64 answer = -1;
        
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_votes = a + mid;
            
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes) - sorted_A.begin();
            int count = N - pos;
            
            if (count < M) {
                i64 sum = 0;
                if (count > 0) {
                    sum = prefix[N] - prefix[N - count];
                }
                i64 remaining = K - mid;
                i64 needed = (new_votes + 1) * count - sum;
                
                if (needed <= remaining) {
                    answer = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                low = mid + 1;
            }
        }
        
        cout << answer << ' ';
    }
    cout << '\n';
    
    return 0;
}