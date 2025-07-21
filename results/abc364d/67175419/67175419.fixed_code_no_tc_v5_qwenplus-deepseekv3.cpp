#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    while (Q--) {
        int b, k;
        cin >> b >> k;
        
        int low = 0, high = 2e8;
        int answer = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            auto left = lower_bound(A.begin(), A.end(), b - mid);
            auto right = upper_bound(A.begin(), A.end(), b + mid);
            int count = right - left;
            
            if (count >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        cout << answer << '\n';
    }
    
    return 0;
}