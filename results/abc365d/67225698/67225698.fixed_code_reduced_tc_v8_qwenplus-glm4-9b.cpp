#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define vsort(v) sort(v.begin(), v.end())
#define min_heap priority_queue<ll, vector<ll>, greater<ll>>
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    
    ll ans = 0;
    vector<ll> heights;
    
    for (ll i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            heights.push_back(i - heights.size());
        } else {
            ans += (heights.size() + 1) / 2;
            heights.push_back(i - heights.size());
        }
    }
    
    ans += (heights.size() + 1) / 2;
    heights.push_back(n - heights.size());
    
    for (ll i = 1; i < heights.size() - 1; ++i) {
        if (heights[i] > 1 && heights[i - 1] > 1) {
            ans--;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}