#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());
    
    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        
        ll low = 0, high = 2e14;
        ll answer = 0;
        
        while (low <= high) {
            ll mid = (low + high) / 2;
            ll left = b - mid;
            ll right = b + mid;
            
            auto l = lower_bound(a.begin(), a.end(), left);
            auto r = upper_bound(a.begin(), a.end(), right);
            int count = r - l;
            
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