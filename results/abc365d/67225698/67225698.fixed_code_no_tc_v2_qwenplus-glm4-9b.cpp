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
#define MOD 1e9 + 7
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

void compute();

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    
    // Calculate the number of blocks along each direction
    ll vertical_blocks = 1, horizontal_blocks = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == '^' || s[i] == 'v') {
            vertical_blocks++;
        } else if (s[i] == '<' || s[i] == '>') {
            horizontal_blocks++;
        }
        // If the current direction is different from the previous one, add
        // half the product of the blocks in both directions (rounded up) to the answer
        if ((s[i] == '^' || s[i] == 'v') != (s[i - 1] == '^' || s[i - 1] == 'v')) {
            ans += (vertical_blocks * horizontal_blocks + 1) / 2;
        } else if ((s[i] == '<' || s[i] == '>') != (s[i - 1] == '<' || s[i - 1] == '>')) {
            ans += (vertical_blocks * horizontal_blocks + 1) / 2;
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
    compute();
    while (t--)
    {
        solve();
    }
    return 0;
}