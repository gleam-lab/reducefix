#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep1(a)          for(ll i = 0; i < (ll)(a); i++)
#define rep2(i, a)       for(ll i = 0; i < (ll)(a); i++)
#define rep3(i, a, b)    for(ll i = (a); i < (ll)(b); i++)
#define rep4(i, a, b, c) for(ll i = (a); i < (ll)(b); i += (c))

#define fi first
#define se second
#define pb push_back
#define spa " "

void print(){cout << '\n';}
template<class T, class... Ts>
void print(const T& a, const Ts&... b){cout << a;(std::cout << ... << (cout << ' ', b));cout << '\n';}

const int MAXN = 2e5 + 10;
pair<int, int> a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        rep1(n) cin >> a[i].fi;
        rep1(n) cin >> a[i].se;
        
        // Sort A in descending order based on A[i].fi
        sort(a, a + n, [&](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.fi > p2.fi;
        });
        
        // Sort B in ascending order based on A[i].se
        rep1(n) b[i] = {a[i].se, a[i].fi};
        sort(b, b + n);
        
        // Initialize variables
        ll ans = LLONG_MAX;
        ll sum_b = 0;
        
        // Calculate initial sum of the first k elements in B
        rep2(i, k) sum_b += b[i].fi;
        
        // Sliding window to find the minimum product
        ans = min(ans, 1LL * sum_b * b[k - 1].se);
        
        rep2(i, k, n) {
            sum_b += b[i].fi - b[i - k].fi;
            ans = min(ans, 1LL * sum_b * b[k - 1].se);
        }
        
        cout << ans << '\n';
    }

    return 0;
}