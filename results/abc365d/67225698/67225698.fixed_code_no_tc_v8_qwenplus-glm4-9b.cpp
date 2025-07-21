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
#define ul unsigned long long
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
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

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    ll cnt = 1; // Start with cnt = 1 to include the first character
    vll v;
    for (int i = 1; i < n; i++) // Start from 1 since we already considered s[0]
    {
        if (s[i] == s[i - 1])
        {
            cnt++;
        }
        else
        {
            ans += (cnt + 1) / 2;
            v.push_back(cnt);
            cnt = 1;
        }
    }
    // Add the last group of consecutive characters
    ans += (cnt + 1) / 2;
    v.push_back(cnt);
    // Check for consecutive groups of the same character
    for (int i = 1; i < v.size() - 1; i++) {
        if (s[i - 1] == s[i] && s[i] == s[i + 1]) {
            // We need to subtract 1 from the answer for each triplet
            ans--;
        }
    }
    cout << ans << "\n";
}

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