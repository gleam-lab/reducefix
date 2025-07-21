#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rrep(i, a, b) for (ll i = a; i >= b; i--)
#define pb push_back
#define mp make_pair

inline void scan() {}
template<class Head, class... Tail>
inline void scan(Head& head, Tail&... tail) {
    cin >> head;
    scan(tail...);
}
#define LL(...) ll __VA_ARGS__; scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; scan(__VA_ARGS__)

void print() { cout << '\n'; }
template<class T, class... Ts>
void print(const T& a, const Ts&... b) {
    cout << a;
    (cout << ... << (cout << ' ', b));
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL(t);
    rep(_, 0, t) {
        LL(n, K);
        vector<pll> ab(n);
        rep(i, 0, n) cin >> ab[i].first;
        rep(i, 0, n) cin >> ab[i].second;
        sort(ab.begin(), ab.end());

        priority_queue<ll> pq;
        ll sum = 0;
        ll ans = LLONG_MAX;

        rep(i, 0, n) {
            sum += ab[i].second;
            pq.push(ab[i].second);
            if (pq.size() > K) {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) {
                ans = min(ans, ab[i].first * sum);
            }
        }
        print(ans);
    }
}