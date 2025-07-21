#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vi vector<int>
#define vl vector<ll>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    vl a(N);
    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());
    
    while (Q--) {
        ll b, k;
        cin >> b >> k;
        
        ll low = 0, high = 2e18;
        ll answer = 0;
        
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            auto left = lower_bound(a.begin(), a.end(), b - mid);
            auto right = upper_bound(a.begin(), a.end(), b + mid);
            ll count = right - left;
            
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