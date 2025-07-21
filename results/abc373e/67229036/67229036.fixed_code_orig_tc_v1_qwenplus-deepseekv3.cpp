#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<int> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end(), greater<int>());
    
    vector<int> prefix_sum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + sorted_A[i];
    }
    
    for (int i = 0; i < N; ++i) {
        int current = A[i];
        int low = 0, high = K;
        int answer = -1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int new_votes = current + mid;
            
            int pos = upper_bound(sorted_A.begin(), sorted_A.end(), new_votes, greater<int>()) - sorted_A.begin();
            
            if (pos < M) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (answer != -1 && answer <= K) {
            cout << answer << " ";
        } else {
            cout << "0 ";
        }
    }
    
    return 0;
}