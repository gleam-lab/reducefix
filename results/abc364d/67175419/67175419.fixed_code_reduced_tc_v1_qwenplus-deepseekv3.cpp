#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    while (Q--) {
        ll b;
        int k;
        cin >> b >> k;
        
        ll low = 0, high = 2e18;
        ll answer = high;
        
        auto count = [&](ll d) -> int {
            ll left = b - d;
            ll right = b + d;
            int l = lower_bound(a.begin(), a.end(), left) - a.begin();
            int r = upper_bound(a.begin(), a.end(), right) - a.begin();
            return r - l;
        };
        
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            int cnt = count(mid);
            if (cnt >= k) {
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