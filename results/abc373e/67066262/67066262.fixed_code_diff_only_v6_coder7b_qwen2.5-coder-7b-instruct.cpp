#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        k -= a[i];
    }
    vector<int> ord(n);
    iota(all(ord),0);
    sort(all(ord),[&](int i,int j) {return a[i] < a[j];});
    vector<ll> suf(n+1);
    for(int i=n-1;i>=0;i--) {
        suf[i] = a[i] + suf[i+1];
    }
    vector<ll> ans(n,-1);
    for(int i=0;i<n;i++) {
        ll l=-1,r=k+1;
        while(r-l>1) {
            ll mid = (l+r)/2;
            ll lft = upper_bound(all(a),a[i]-mid)-a.begin();
            ll rit = n-m - (i < n-m? 1 : 0);
            ll cnt = 0;
            if(lft < rit) cnt += (rit-lft)*(a[i]-mid) - (suf[lft]-suf[rit]);
            if(lft <= i && i < rit) cnt++;
            else cnt -= mid;
            if(cnt > k) {
                r = mid;
            }
            else l = mid;
        }
        if(l == k) ans[ord[i]] = -1;
        else ans[ord[i]] = r;
    }
    for(auto i : ans) cout << i << ' ';
}