#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define OUT(x) cout << #x << ":" << x << endl

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    rep(qi, t){
        int n, k;
        cin >> n >> k;
        vector<pair<ll, ll>> p(n);
        rep(i, n) cin >> p[i].first;
        rep(i, n) cin >> p[i].second;
        sort(p.begin(), p.end());
        multiset<ll> s;
        ll sumB = 0;
        ll ans = LINF;
        for (int i = n - 1; i >= 0; --i) {
            s.insert(p[i].second);
            sumB += p[i].second;
            if (s.size() > k) {
                auto it = s.begin();
                sumB -= *it;
                s.erase(it);
            }
            if (s.size() == k) {
                ans = min(ans, p[i].first * sumB);
            }
        }
        cout << ans << '\n';
    }
}