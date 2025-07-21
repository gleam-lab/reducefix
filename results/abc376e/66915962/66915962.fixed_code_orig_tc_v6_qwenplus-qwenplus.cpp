#include <bits/stdc++.h>
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    rep(qi, t){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        vector<pair<ll, ll>> p(n);
        rep(i, n) cin >> p[i].first;
        rep(i, n) cin >> p[i].second;
        
        // Sort by A_i in ascending order
        sort(p.begin(), p.end());
        rep(i, n){
            a[i] = p[i].first;
            b[i] = p[i].second;
        }

        ll ans = LINF;
        ll sumB = 0;
        // We use multiset to handle duplicate values correctly
        multiset<ll> s;

        // Initialize with the first K elements
        rep(i, k){
            s.insert(b[i]);
            sumB += b[i];
        }
        ans = min(ans, a[k-1] * sumB);

        rep(i, n - k){
            // Remove the largest B from current window
            auto it = prev(s.end());
            sumB -= *it;
            s.erase(it);

            // Add new element
            s.insert(b[i + k]);
            sumB += b[i + k];

            ans = min(ans, a[i + k] * sumB);
        }

        cout << ans << '\n';
    }

    return 0;
}