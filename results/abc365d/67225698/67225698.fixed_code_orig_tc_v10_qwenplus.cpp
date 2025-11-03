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
#define fi first
#define se second
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
vll row{0, 1, 0, -1};
vll col{1, 0, -1, 0};
vector<char> s{'<', '^', '>', 'v'};
ll gcd(ll a, ll b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

void solve();
void compute();
int main()
{
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    // compute();
    while (t--)
    {
        solve();
    }
    return 0;
}
// ****************************** ACTUAL CODE ****************************** //
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    
    if (n == 0) {
        cout << 0 << "\n";
        return;
    }
    
    ll ans = 0;
    ll cnt = 1; // Start counting from the first character
    
    // Traverse from second character onwards
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            cnt++;
        } else {
            ans += (cnt + 1) / 2;
            cnt = 1;
        }
    }
    ans += (cnt + 1) / 2; // Add last group
    
    // Now handle overlapping cases: when we have two consecutive groups of size > 1
    // This optimization reduces answer by 1 for each such adjacent large group
    vector<ll> groups;
    ll current = 1;
    
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            current++;
        } else {
            groups.push_back(current);
            current = 1;
        }
    }
    groups.push_back(current);
    
    // Check adjacent groups: if both are > 1, we can save one operation
    for (int i = 0; i < (int)groups.size()-1; i++) {
        if (groups[i] > 1 && groups[i+1] > 1) {
            ans--;
        }
    }
    
    cout << ans << "\n";
}