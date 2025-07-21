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
        long long b, k;
        cin >> b >> k;
        
        long long low = 0, high = 2e18;
        long long answer = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            auto left = lower_bound(A.begin(), A.end(), b - mid);
            auto right = upper_bound(A.begin(), A.end(), b + mid);
            long long count = right - left;
            
            if (count < k) {
                low = mid + 1;
            } else {
                answer = mid;
                high = mid - 1;
            }
        }
        
        cout << answer << '\n';
    }
    
    return 0;
}