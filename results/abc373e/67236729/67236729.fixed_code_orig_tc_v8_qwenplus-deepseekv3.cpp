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
    
    vector<i64> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }
    
    i64 remaining_votes = K;
    for (i64 a : A) {
        remaining_votes -= a;
    }
    
    for (int i = 0; i < N; ++i) {
        i64 current = A[i];
        i64 low = 0, high = remaining_votes, answer = -1;
        
        while (low <= high) {
            i64 mid = (low + high) / 2;
            i64 new_vote = current + mid;
            
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_vote) - sorted_A.begin();
            int better = N - pos;
            
            if (better < M) {
                answer = mid;
                high = mid - 1;
            } else {
                i64 needed = 0;
                int start_pos = pos - (better - (M - 1));
                if (start_pos < 0) {
                    start_pos = 0;
                }
                
                needed = new_vote * (better - (M - 1)) - (prefix_sum[pos] - prefix_sum[start_pos]);
                
                if (needed <= remaining_votes - mid) {
                    answer = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        
        cout << (answer != -1 ? answer : -1) << " ";
    }
    
    cout << "\n";
    
    return 0;
}