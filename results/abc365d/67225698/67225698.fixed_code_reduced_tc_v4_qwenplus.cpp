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
vector<char> dir{'<', '^', '>', 'v'};
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
    
    // Traverse the string to process consecutive groups
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            cnt++;
        } else {
            ans += (cnt + 1) / 2; // Ceiling division: number of moves needed for this block
            cnt = 1;
        }
    }
    // Add the last group
    ans += (cnt + 1) / 2;
    
    // Now check for adjacent blocks of size > 1 that can be optimized
    vector<ll> blocks;
    cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            cnt++;
        } else {
            blocks.push_back(cnt);
            cnt = 1;
        }
    }
    blocks.push_back(cnt);
    
    // If there are at least 3 blocks and middle block has size >=2 and both neighbors have size >=2,
    // then we can save one move when merging
    for (int i = 1; i < (int)blocks.size() - 1; i++) {
        if (blocks[i] >= 2 && blocks[i-1] >= 2 && blocks[i+1] >= 2) {
            ans--;
            // We break here because we can only apply this optimization once due to overlapping constraints
            // But actually, multiple non-overlapping such patterns may exist.
            // However, based on problem logic, each such triplet reduces cost by 1 independently?
            // Let's reconsider: each isolated peak (block surrounded by >=2 length blocks) allows saving one operation.
            // So we don't break — but in initial testing, let's assume independent savings.
            // Actually, after analysis: yes, each such interior block with all neighbors >=2 saves one.
        }
    }
    
    cout << ans << "\n";
}