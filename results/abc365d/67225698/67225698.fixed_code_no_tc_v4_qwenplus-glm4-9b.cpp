#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, greater<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
#define pq priority_queue<long long, vector<long long>, greater<long long>>
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
    ll ans = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || s[i] != s[i - 1])
        {
            if (cnt > 0)
            {
                ans += (cnt + 1) / 2;
            }
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    if (cnt > 0)
    {
        ans += (cnt + 1) / 2;
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