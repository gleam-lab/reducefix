#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    
    sort(A.begin(), A.end());
    
    rep(_, Q) {
        ll b, k;
        cin >> b >> k;
        
        // Binary search the distance d such that there are at least k points within distance d from b
        ll left = 0, right = 2e18;
        ll answer = 0;
        
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            
            // Count the number of A_i <= b + mid and >= b - mid
            ll low = b - mid;
            ll high = b + mid;
            
            auto it_low = lower_bound(A.begin(), A.end(), low);
            auto it_high = upper_bound(A.begin(), A.end(), high);
            ll count = it_high - it_low;
            
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