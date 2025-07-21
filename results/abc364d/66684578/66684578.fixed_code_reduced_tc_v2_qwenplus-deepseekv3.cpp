#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    
    while (Q--) {
        ll b, k;
        cin >> b >> k;
        
        ll left = 0;
        ll right = 2e18;
        ll answer = 0;
        
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            
            auto lower = lower_bound(A.begin(), A.end(), b - mid);
            auto upper = upper_bound(A.begin(), A.end(), b + mid);
            ll count = upper - lower;
            
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