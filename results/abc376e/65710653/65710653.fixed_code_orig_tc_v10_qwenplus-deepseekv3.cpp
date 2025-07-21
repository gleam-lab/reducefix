#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;
using pll = pair<long long, long long>;

#define rep1(a)          for(ll i = 0; i < (ll)(a); i++)
#define rep2(i, a)       for(ll i = 0; i < (ll)(a); i++)
#define rep3(i, a, b)    for(ll i = (a); i < (ll)(b); i++)
#define rep4(i, a, b, c) for(ll i = (a); i < (ll)(b); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep1(a)          for(ll i = (ll)(a-1); i >= (ll)0 ; i--)
#define rrep2(i, a)       for(ll i = (ll)(a-1); i >= (ll)0; i--)
#define rrep3(i, a, b)    for(ll i = (ll)(a-1); i >=(b); i--)
#define rrep4(i, a, b, c) for(ll i = (ll)(a-1); i >=(b); i -= (c))
#define overload4(a, b, c, d, e, ...) e
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define fi first
#define se second
#define pb push_back
#define spa " "

inline void scan(){}
template<class Head,class... Tail>
inline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)

void print(){cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(std::cout << ... << (cout << ' ', b));cout << '\n';}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL(t);
    rep(t){
        LL(n,K);
        vector<pll> pairs(n);
        rep(n) cin >> pairs[i].fi;
        rep(n) cin >> pairs[i].se;
        
        sort(pairs.begin(), pairs.end());
        
        priority_queue<ll> pq;
        ll sum = 0;
        
        // Precompute prefix sums of smallest K-1 B's
        rep(i, K-1){
            pq.push(pairs[i].se);
            sum += pairs[i].se;
        }
        
        vector<ll> prefix(n+1);
        prefix[K-1] = sum;
        rep(i, K, n){
            if (pairs[i-1].se < pq.top()){
                sum -= pq.top();
                pq.pop();
                sum += pairs[i-1].se;
                pq.push(pairs[i-1].se);
            }
            prefix[i] = sum;
        }
        
        ll ans = LLONG_MAX;
        rep(i, K-1, n){
            ll current = pairs[i].fi * (prefix[i] + pairs[i].se);
            if (current < ans) ans = current;
        }
        
        cout << ans << endl;
    }
}