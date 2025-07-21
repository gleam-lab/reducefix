#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b,c) for(int i=a;i<b;i+=c)
#define repv(i,n) for(auto &i:n)

const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<pi> villages(n);
    rep(i, n) {
        cin >> villages[i].first;
    }
    rep(i, n) {
        cin >> villages[i].second;
    }

    sort(villages.begin(), villages.end());

    vector<ll> prefix_sum(n + 1);
    rep(i, n) {
        prefix_sum[i + 1] = prefix_sum[i] + villages[i].second;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        auto it_l = lower_bound(villages.begin(), villages.end(), make_pair(l, 0));
        auto it_r = upper_bound(villages.begin(), villages.end(), make_pair(r, INF));

        int idx_l = distance(villages.begin(), it_l);
        int idx_r = distance(villages.begin(), it_r);

        ll result = prefix_sum[idx_r] - prefix_sum[idx_l];

        cout << result << "\n";
    }

    return 0;
}