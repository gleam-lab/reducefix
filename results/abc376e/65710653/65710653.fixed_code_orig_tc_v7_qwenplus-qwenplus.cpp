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

inline void scan() {}
template<class Head, class... Tail>
inline void scan(Head& head, Tail&... tail) {
    cin >> head;
    scan(tail...);
}
#define LL(...) ll __VA_ARGS__; scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; scan(__VA_ARGS__)

#pragma GCC diagnostic ignored "-Wunused-value"
void print() { cout << '\n'; }
template<class T, class... Ts>
void print(const T& a, const Ts&... b) {
    cout << a;
    (cout << ... << (cout << ' ', b));
    cout << '\n';
}
#pragma GCC diagnostic warning "-Wunused-value"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL(t);
    while (t--) {
        LL(n, k);
        vector<pll> pairs(n);
        for (ll i = 0; i < n; ++i) {
            cin >> pairs[i].first;
        }
        for (ll i = 0; i < n; ++i) {
            cin >> pairs[i].second;
        }

        sort(pairs.begin(), pairs.end());

        multiset<ll> ms;
        ll sum = 0;
        for (ll i = 0; i < k; ++i) {
            ms.insert(pairs[i].second);
            sum += pairs[i].second;
        }

        ll ans = sum * pairs[k - 1].first;

        for (ll i = 0; i < n - k; ++i) {
            // Remove the largest B in current set
            sum -= *ms.rbegin();
            ms.erase(ms.find(*ms.rbegin()));

            // Add new element
            ms.insert(pairs[i + k].second);
            sum += pairs[i + k].second;

            ans = min(ans, sum * pairs[i + k].first);
        }

        cout << ans << "\n";
    }

    return 0;
}