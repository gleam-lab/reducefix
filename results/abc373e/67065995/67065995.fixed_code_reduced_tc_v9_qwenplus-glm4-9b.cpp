#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main()
{
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
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) {
        return a[i] > a[j];
    });
    auto b = a;
    sort(all(b));
    vector<ll> pref(n + 1);
    for(int i = 0; i < n; i++) {
        pref[i + 1] = b[i] + pref[i];
    }
    vector<ll> ans(n, -1);
    for(int i = 0; i < n; i++) {
        ll max_votes = k + a[i];
        ll min_votes_needed = max_votes - m + 1;
        ll max_votes_possible = max_votes;
        if(min_votes_needed > max_votes_possible) {
            ans[ord[i]] = -1;
            continue;
        }
        auto it = lower_bound(all(b), min_votes_needed);
        ll votes_needed = min_votes_needed - b[it - 1];
        ans[ord[i]] = votes_needed;
    }
    for(auto i : ans) cout << i << ' ';
}