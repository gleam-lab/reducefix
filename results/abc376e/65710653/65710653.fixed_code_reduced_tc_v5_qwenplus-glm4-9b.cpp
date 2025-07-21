#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

#define rrep1(a)          for(ll i = (ll)(a-1); i >= (ll)0 ; i--)
#define rrep2(i, a)       for(ll i = (ll)(a-1); i >= (ll)0; i--)
#define rrep3(i, a, b)    for(ll i = (ll)(a-1); i >=(b); i--)
#define rrep4(i, a, b, c) for(ll i = (ll)(a-1); i >=(b); i -= (c))
#define overload4(a, b, c, d, e, ...) e
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define rep1(a)          for(ll i = 0; i < (ll)(a); i++)
#define rep2(i, a)       for(ll i = 0; i < (ll)(a); i++)
#define rep3(i, a, b)    for(ll i = (a); i < (ll)(b); i++)
#define rep4(i, a, b, c) for(ll i = (a); i < (ll)(b); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define fi first
#define se second
#define pb push_back
#define spa " "

void print(){cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(std::cout << ... << (cout << ' ', b));cout << '\n';}

ll inf = 1LL << 60;
int main(){
    ll t;
    cin >> t;
    rep(t){
        ll n, m;
        cin >> n >> m;
        vector<pll> a(n);
        vector<ll> b(n);
        rep(n) cin >> a[i].fi >> b[i];
        // Sort by A first, then by B if A is equal
        sort(a.begin(), a.end());
        multiset<ll> s;
        ll sum = 0;
        rep(m) s.insert(b[i]);
        rep(m) sum += b[i];

        ll ans = sum * a[m - 1].fi;
        for(ll i = 0; i < n - m; i++){
            sum -= b[i];
            s.erase(b[i]);
            s.insert(b[i + m]);
            sum += b[i + m];
            ans = min(ans, sum * a[i + m].fi);
        }
        cout << ans << endl;
    }
}