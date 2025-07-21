#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
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
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return a[i] < a[j]; });
    
    auto b = a;
    sort(all(b));
    
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = b[i] + pref[i];
    }
    
    vector<ll> ans(n, -1);
    
    for(int i = 0; i < n; ++i) {
        ll l = -1, r = k + 1;
        
        while(r - l > 1) {
            ll mid = (l + r) / 2;
            
            ll rid = lower_bound(all(b), b[i] + mid + 1) - b.begin();
            ll lid = n - m - (i >= n - m ? 1 : 0);
            
            ll cnt = 0;
            if(rid > lid) {
                cnt += (rid - lid) * (b[i] + mid + 1) - (pref[rid] - pref[lid]);
            }
            if(lid <= i && i < rid) {
                cnt--;
            } else {
                cnt += mid;
            }
            
            if(cnt > k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        
        if(l == k) {
            ans[ord[i]] = -1;
        } else {
            ans[ord[i]] = r;
        }
    }
    
    for(auto i : ans) cout << i << ' ';
    
    return 0;
}