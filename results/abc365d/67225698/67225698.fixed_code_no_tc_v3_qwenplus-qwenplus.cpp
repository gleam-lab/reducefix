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
#define pll pair<long long, long_long>
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
    cin >> t;
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

    vll groups;
    ll cnt = 1;

    // Group consecutive characters and count their lengths
    for (ll i = 1; i < n; ++i)
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
        }
        else
        {
            groups.push_back(cnt);
            cnt = 1;
        }
    }
    groups.push_back(cnt); // Push the last group

    ll ans = 0;

    // Count number of pairs by dividing each group length by 2
    for (ll len : groups)
    {
        ans += len / 2;
    }

    cout << ans << "\n";
}