#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    i64 N, M, K;
    cin >> N >> M >> K;
    vector<i64> A(N);
    for (i64 &a : A) cin >> a;
    
    vector<i64> sortedA = A;
    sort(sortedA.begin(), sortedA.end());
    
    vector<i64> prefixSum(N + 1);
    for (i64 i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + sortedA[i];
    }
    
    for (i64 i = 0; i < N; ++i) {
        i64 a = A[i];
        
        i64 low = 0, high = K;
        i64 answer = -1;
        
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_vote = a + mid;
            
            i64 pos = upper_bound(sortedA.begin(), sortedA.end(), new_vote) - sortedA.begin();
            i64 count_less_equal = pos;
            if (sortedA[pos - 1] == new_vote) {
                count_less_equal = pos;
            } else {
                count_less_equal = pos;
            }
            
            i64 needed = max(0LL, N - count_less_equal - (M - 1));
            
            i64 total = 0;
            if (needed > 0) {
                i64 start = N - needed;
                total = prefixSum[N] - prefixSum[start] - new_vote * needed;
            }
            
            if (total + mid <= K) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << answer << " ";
    }
    cout << endl;
    
    return 0;
}