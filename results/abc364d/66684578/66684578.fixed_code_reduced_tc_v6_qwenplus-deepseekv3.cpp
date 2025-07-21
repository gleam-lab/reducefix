#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    rep(i, q) {
        ll b, k;
        cin >> b >> k;
        ll left = 0;
        ll right = 2e18;
        ll answer = 0;
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            auto lower = lower_bound(a.begin(), a.end(), b - mid);
            auto upper = upper_bound(a.begin(), a.end(), b + mid);
            ll count = distance(lower, upper);
            if (count >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        cout << answer << endl;
    }
    
    return 0;
}