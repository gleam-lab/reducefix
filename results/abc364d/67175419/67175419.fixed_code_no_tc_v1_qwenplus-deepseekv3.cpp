#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    while (Q--) {
        long long b_j, k_j;
        cin >> b_j >> k_j;
        
        long long left = 0, right = 2e14;
        long long answer = 0;
        
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long lower = b_j - mid;
            long long upper = b_j + mid;
            
            auto it_low = lower_bound(A.begin(), A.end(), lower);
            auto it_up = upper_bound(A.begin(), A.end(), upper);
            long long count = it_up - it_low;
            
            if (count >= k_j) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << answer << "\n";
    }
    
    return 0;
}