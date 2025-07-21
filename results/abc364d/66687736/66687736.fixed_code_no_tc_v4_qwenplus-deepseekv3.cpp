#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
        ll low = 0, high = 2e14;
        ll answer = 0;
        while (low <= high) {
            ll mid = (low + high) / 2;
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
        cout << answer << "\n";
    }
    return 0;
}