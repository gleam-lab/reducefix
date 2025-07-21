#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define vi vector<int>
#define vl vector<ll>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    vi A(N);
    rep(i, N) cin >> A[i];
    
    sort(A.begin(), A.end());
    
    rep(_, Q) {
        ll b, k;
        cin >> b >> k;
        
        ll low = 0, high = 2e18;
        ll answer = 0;
        
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            
            ll left = b - mid;
            ll right = b + mid;
            
            auto it_l = lower_bound(A.begin(), A.end(), left);
            auto it_r = upper_bound(A.begin(), A.end(), right);
            ll count = it_r - it_l;
            
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