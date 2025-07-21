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
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<i64> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    vector<i64> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix[i + 1] = prefix[i] + sorted_A[i];
    }
    
    vector<i64> res(N);
    for (int i = 0; i < N; ++i) {
        i64 a = A[i];
        i64 low = 0, high = K, ans = -1;
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_val = a + mid;
            
            // Find the number of elements > new_val
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_val) - sorted_A.begin();
            int cnt = N - pos;
            
            if (cnt < M) {
                // Need to ensure that at most M-1 candidates have more votes
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (ans != -1) {
            // Check if we can distribute the remaining votes to not exceed M-1 candidates
            i64 new_val = a + ans;
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_val) - sorted_A.begin();
            int cnt = N - pos;
            
            if (cnt >= M) {
                ans = -1;
            } else {
                // Calculate the sum of the top M - cnt - 1 elements <= new_val
                int needed = M - cnt - 1;
                if (needed > 0) {
                    int start_pos = pos - needed;
                    if (start_pos < 0) {
                        ans = -1;
                    } else {
                        i64 sum = prefix[pos] - prefix[start_pos];
                        i64 remaining_votes = K - ans;
                        if (sum + remaining_votes < new_val * needed) {
                            ans = -1;
                        }
                    }
                }
            }
        }
        
        res[i] = ans;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    return 0;
}