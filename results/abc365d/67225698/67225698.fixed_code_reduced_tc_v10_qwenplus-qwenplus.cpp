#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vsort(v) sort(v.begin(), v.end())
#define min_heap priority_queue<ll, vll, greater<ll>>
#define min_heap_pll priority_queue<pll, vector<pll>, greater<pll>>
#define max_heap priority_queue<ll>
#define max_heap_pll priority_queue<pll>

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
vector<ll> row{0, 1, 0, -1};
vector<ll> col{1, 0, -1, 0};
vector<char> dir{'<', '^', '>', 'v'};

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

void solve();
int main() {
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
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

    if (n == 0) {
        cout << 0 << "\n";
        return;
    }

    ll ans = 0;
    ll cnt = 1;
    vector<ll> runs;

    for (ll i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            cnt++;
        } else {
            runs.push_back(cnt);
            ans += (cnt + 1) / 2;
            cnt = 1;
        }
    }
    runs.push_back(cnt);
    ans += (cnt + 1) / 2;

    // Optimization: reduce answer when we can merge segments
    for (ll i = 1; i < runs.size() - 1; ++i) {
        if (runs[i] == 1 && runs[i - 1] > 0 && runs[i + 1] > 0) {
            ans -= 1;  // Can save one operation by merging
        }
    }

    cout << ans << "\n";
}