#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
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
        
        int left = 0;
        long long right = 2e18; // Sufficiently large to cover max possible distance
        
        while (left < right) {
            long long mid = left + (right - left) / 2;
            int count = upper_bound(A.begin(), A.end(), b + mid) - lower_bound(A.begin(), A.end(), b - mid);
            
            if (count >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        cout << left << "\n";
    }
    
    return 0;
}