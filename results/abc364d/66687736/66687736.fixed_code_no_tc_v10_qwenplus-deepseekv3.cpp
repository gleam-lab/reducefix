#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vi vector<int>
#define vl vector<ll>
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    vi a(N);
    rep(i, N) cin >> a[i];
    sort(all(a));
    
    rep(i, Q) {
        int b, k;
        cin >> b >> k;
        
        int low = 0, high = 2e8;
        int answer = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            ll left = b - mid;
            ll right = b + mid;
            
            auto it_left = lower_bound(all(a), left);
            auto it_right = upper_bound(all(a), right);
            int count = it_right - it_left;
            
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