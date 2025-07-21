#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<int> ord(n);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) { return a[i] < a[j]; });

    auto b = a;
    sort(begin(b), end(b));

    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = b[i] + pref[i];
    }

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        int lid = n - m - (i >= n - m ? 1 : 0);
        if(lid < 0) continue;

        ll sum = pref[lid + 1];
        ll target = b[lid] + 1;
        ll left = 0, right = k + 1;
        
        while(left < right) {
            ll mid = (left + right) / 2;
            auto rid = upper_bound(begin(b), begin(b) + min(lid + 1, n), target + mid) - begin(b);
            if(rid > lid) sum += (rid - lid - 1) * (target + mid) - (pref[rid] - pref[lid + 1]);
            if(lid <= i && i < rid) sum++;
            else sum += mid;
            
            if(sum > k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        if(left == k + 1) ans[ord[i]] = -1;
        else ans[ord[i]] = left;
    }

    for(auto i : ans) cout << i << " ";
    cout << endl;

    return 0;
}