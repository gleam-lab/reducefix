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
    }
    
    vector<i64> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());
    
    vector<i64> prefix_sum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }
    
    for (int i = 0; i < N; ++i) {
        i64 a = A[i];
        i64 low = 0, high = K, answer = -1;
        
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_votes = a + mid;
            
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes);
            int cnt = sorted_A.end() - it;
            
            if (cnt < M) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (answer != -1) {
            i64 new_votes = a + answer;
            auto it = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes);
            int cnt = sorted_A.end() - it;
            
            if (cnt >= M) {
                answer = -1;
            } else {
                i64 required = 0;
                if (cnt > 0) {
                    int start_pos = N - cnt;
                    required = new_votes * cnt - (prefix_sum[N] - prefix_sum[start_pos]);
                }
                
                if (required > (K - answer)) {
                    answer = -1;
                }
            }
        }
        
        cout << answer << " ";
    }
    cout << "\n";
    
    return 0;
}