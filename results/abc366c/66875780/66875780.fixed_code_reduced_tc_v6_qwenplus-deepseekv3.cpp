#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <limits>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Solve()
{
    ll Q;
    cin >> Q;
    unordered_map<ll, ll> count;
    set<ll> distinct;
    while (Q--)
    {
        ll a;
        cin >> a;
        if (a == 1)
        {
            ll x;
            cin >> x;
            count[x]++;
            if (count[x] == 1)
            {
                distinct.insert(x);
            }
        }
        else if (a == 2)
        {
            ll x;
            cin >> x;
            count[x]--;
            if (count[x] == 0)
            {
                distinct.erase(x);
            }
        }
        else
        {
            cout << distinct.size() << "\n";
        }
    }
}

int main()
{
    fastIO();

    int t = 1;
    while (t--)
    {
        Solve();
    }

    return 0;
}