#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(vector<ll>& a, vector<ll>& b, vector<int>& ord, int x, int m, ll k) {
    int n = a.size();
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; ++i) {
        pref[i + 1] = b[i] + pref[i];
    }

    for(int i = 0; i < n; ++i) {
        int id = ord[i];
        ll left_votes = pref[id] + x;
        int rid = upper_bound(b.begin(), b.end(), left_votes) - b.begin();
        int lid = n - m - (id >= n - m ? 1 : 0);

        ll cnt = 0;
        if(rid > lid) cnt += (rid - lid) * (left_votes + 1) - (pref[rid] - pref[lid]);
        if(lid <= id && id < rid) cnt--;
        else cnt += x;

        if(cnt > k) return false;
    }

    return true;
}

vector<ll> min_additional_votes(vector<ll>& a, int m, ll k) {
    int n = a.size();
    vector<ll> b = a;
    sort(b.rbegin(), b.rend());
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        int id = ord[i];
        if(a[id] >= k) continue;

        int l = 0, r = k - a[id];
        while(l <= r) {
            int mid = (l + r) / 2;
            if(check(a, b, ord, mid, m, k)) {
                ans[id] = mid;
                break;
            } else {
                l = mid + 1;
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    vector<ll> result = min_additional_votes(a, m, k);
    
    for(ll val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}