#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    while (Q--) {
        ll b, k;
        cin >> b >> k;
        
        ll low = 0, high = 2e18;
        ll answer = 0;
        
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            auto it_low = lower_bound(A.begin(), A.end(), b - mid);
            auto it_high = upper_bound(A.begin(), A.end(), b + mid);
            ll count = it_high - it_low;
            
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