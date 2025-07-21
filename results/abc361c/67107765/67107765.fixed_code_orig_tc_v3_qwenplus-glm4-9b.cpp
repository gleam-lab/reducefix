#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
using ll = long long;
using P = pair<ll, ll>;
const ll LINF = 1001002003004005006ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    // We consider removing from 0 to min(k, n/2) elements to minimize the range.
    ll ans = LINF;
    for (int i = 0; i <= min(k, n/2); i++) {
        ll min_val = nums[i];
        ll max_val = nums[n - k + i]; // Note: k-i is effectively (n-i-1)
        ans = min(ans, max_val - min_val);
    }

    cout << ans << endl;
    return 0;
}