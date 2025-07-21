#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // If this header is not automatically included
using namespace std;
using namespace __gnu_pbds;

typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define fast_io()                                     \
    ios_base::sync_with_stdio(false);                 \
    cin.tie(NULL);                                    \
    cout.tie(NULL)

#define ll long long
#define MOD 1e9 + 7
#define INF 1e18

vll row{0, 1, 0, -1};
vll col{1, 0, -1, 0};
vector<char> s{'<', '^', '>', 'v'};
ll gcd(ll a, ll b) {
    while (b)
        a %= b, swap(a, b);
    return a;
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

void solve();
void compute(); // Assuming compute exists and does something

int main() {
    fast_io();
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    // cin >> t;
    // compute(); // Assuming compute exists and should be called before the loop
    while (t--) {
        solve();
    }
    return 0;
}
void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    ll cnt = 0;
    vll v;
    for (int i = 0; i < n; i++) {
        if (i == 0 || s[i] == s[i - 1]) {
            cnt++;
        } else {
            ans += (cnt + 1) / 2;
            v.push_back(cnt);
            cnt = 1;
        }
    }
    ans += (cnt + 1) / 2;
    v.push_back(cnt);
    for(int i = 1; i < v.size() - 1; i++) {
        if(v[i] > 1 && v[i - 1] > 1) {
            ans -= 1;
        }
    }
    cout << ans << "\n";
}