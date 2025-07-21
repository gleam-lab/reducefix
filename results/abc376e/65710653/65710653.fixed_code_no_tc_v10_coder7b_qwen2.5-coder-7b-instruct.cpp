#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

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

#define O print

inline void scan(){}
template<class Head,class... Tail>
inline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)

#pragma GCC diagnostic ignored "-Wunused-value"
void print(){cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(std::cout << ... << (cout << ' ', b));cout << '\n';}
#pragma GCC diagnostic warning "-Wunused-value"

int main(){
    LL(t);
    while(t--){
        LL(n,k);
        vector<ll> a(n), b(n);
        rep(n) cin >> a[i];
        rep(n) cin >> b[i];
        
        priority_queue<ll> pq_a(a.begin(), a.end());
        priority_queue<ll, vector<ll>, greater<ll>> pq_b(b.begin(), b.end());
        
        ll max_a = pq_a.top(); pq_a.pop();
        ll sum_b = 0;
        rep(k-1){
            sum_b += pq_b.top(); pq_b.pop();
        }
        
        ll ans = max_a * sum_b;
        for(int i=1; i<=n-k+1; ++i){
            sum_b += pq_b.top() - pq_b.size()-k+1;
            pq_b.pop();
            pq_b.push(a[n-i]);
            ans = min(ans, max_a * sum_b);
        }
        
        cout << ans << endl;
    }
    return 0;
}