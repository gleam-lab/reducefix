#include <bits/stdc++.h>
using namespace std;

#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define RREP(i, n) for (ll i = n - 1; i >= 0; --i)
#define REPR(i, l, r) for (ll i = r; i >= l; --i)

void scan(){}
template<class Head,class... Tail>
inline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}

void print(){cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(std::cout << ... << (cout << ' ', b));cout << '\n';}

int main() {
    LL(t);
    while (t--) {
        LL(n, k);
        vector<pair<int, int>> ab(n);
        REP(i, n) cin >> ab[i].first >> ab[i].second;
        
        sort(ab.begin(), ab.end(), [&](const auto &a, const auto &b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        });
        
        vector<int> sorted_b(n);
        REP(i, n) sorted_b[i] = ab[i].second;
        
        multiset<int> ms(sorted_b.begin(), sorted_b.begin() + k);
        int sum = accumulate(ms.begin(), ms.end(), 0);
        int ans = sum * ab[k - 1].first;
        
        RREP(i, n - k) {
            ms.erase(ms.find(sorted_b[i]));
            ms.insert(sorted_b[i + k]);
            sum += sorted_b[i + k] - sorted_b[i];
            ans = min(ans, sum * ab[i + k].first);
        }
        
        cout << ans << '\n';
    }
    return 0;
}