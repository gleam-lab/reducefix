#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    vector<pair<ll, ll>> ab(n);
    
    rep(i, n) {
        cin >> a[i];
        cin >> b[i];
        ab[i] = {a[i], b[i]};
    }

    sort(ab.begin(), ab.end());

    ll ans = LINF;
    ll sumB = 0;
    multiset<ll> s;
    rep(i, k) {
        s.insert(ab[i].second);
        sumB += ab[i].second;
    }
    ans = min(ans, ab[k-1].first * sumB);

    rep2(i, k, n) {
        ll smax = *s.rbegin();
        s.erase(s.find(smax));
        s.insert(ab[i].second);
        sumB += ab[i].second - smax;
        
        ans = min(ans, ab[i].first * sumB);
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}