#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep2(i, a, b, c) for (ll i = (a); i < (b); i += c)
#define rep3(i, a, b, c) for (ll i = (a); i <= (b); i += c)
#define rep4(i, a, b, c, d) for (ll i = (a); i < (b); i += (c * d))

#define fi first
#define se second
#define pb push_back

inline void scan() {}
template <class Head, class... Tail>
inline void scan(Head&head, Tail&... tail){ std::cin >> head; scan(tail...); }
#define LL(...) ll __VA_ARGS__; scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; scan(__VA_ARGS__)

void print() { cout << '\n'; }
template <class T, class... Ts>
void print(const T& a, const Ts&... b){ cout << a; (cout << ' ' << b...); cout << '\n'; }

ll inf = 1LL << 60;

int main() {
    LL(t);
    rep(t) {
        LL(n, m);
        vector<pair<ll, ll>> a(n);
        rep(n) cin >> a[i].fi >> a[i].se;
        sort(a.rbegin(), a.rend()); // Sort descending by A, then by B if A's are equal
        
        ll sumB = 0;
        multiset<ll> sB;
        rep(m) {
            sumB += a[i].se;
            sB.insert(a[i].se);
        }
        
        ll ans = sumB * a[m - 1].fi;
        
        rep(n - m) {
            sumB -= *sB.rbegin();
            sB.erase(sB.find(*sB.rbegin()));
            
            sumB += a[i + m].se;
            sB.insert(a[i + m].se);
            
            ans = min(ans, sumB * a[i + m].fi);
        }
        
        print(ans);
    }
}