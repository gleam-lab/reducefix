#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    vector<pair<ll, int>> p(n);
    for(int i = 0; i < n; i++) {
        p[i] = {a[i], i};
    }

    sort(p.rbegin(), p.rend());

    vector<ll> pref(n + 1);
    for(int i = 0; i < n; i++) {
        pref[i + 1] = p[i].first + pref[i];
    }

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; i++) {
        int idx = p[i].second;
        ll need = 0;

        // Calculate the minimum votes needed
        for(int j = 0; j < min(m - 1, i); j++) {
            need += max(0LL, p[j].first - p[i].first + 1);
        }

        // Check if the current candidate can win with need votes
        if(k >= need) {
            ans[idx] = need;
        } else {
            // Binary search for the exact minimum votes needed
            ll l = 0, r = k + 1;
            while(l < r) {
                ll mid = (l + r) / 2;
                ll cnt = 0;

                for(int j = 0; j < min(m - 1, i); j++) {
                    cnt += max(0LL, p[j].first - (p[i].first + mid) + 1);
                }

                if(cnt > k) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            ans[idx] = l;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}