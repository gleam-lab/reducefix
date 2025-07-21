#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    while (Q--) {
        long long b;
        int k;
        cin >> b >> k;
        
        int left = 0;
        int right = 2e18;
        long long answer = 0;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            auto lower = lower_bound(A.begin(), A.end(), b - mid);
            auto upper = upper_bound(A.begin(), A.end(), b + mid);
            int count = upper - lower;
            
            if (count >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        cout << answer << '\n';
    }
    
    return 0;
}