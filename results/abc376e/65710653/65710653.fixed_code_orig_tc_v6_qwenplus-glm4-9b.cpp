#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

void print() {cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(std::cout << ... << (cout << ' ', b));cout << '\n';}

int main() {
    ll n, k;
    while (cin >> n >> k) {
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());

        ll sum = 0, max_a = a[0], min_expr = LLONG_MAX;
        for (int i = 0; i < k; i++) {
            sum += b[i];
            max_a = max(max_a, a[i]);
            min_expr = min(min_expr, max_a * sum);
        }
        cout << min_expr << endl;

        for (int i = k; i < n; i++) {
            sum += b[i] - b[i - k];
            max_a = max(max_a, a[i]) - min(a[i - k], a[i]);
            min_expr = min(min_expr, max_a * sum);
        }
        cout << min_expr << endl;
    }
}