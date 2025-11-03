#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

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
    multiset<ll> s; // Use multiset to allow multiple balls with the same number
    while (Q--)
    {
        ll a;
        cin >> a;
        if (a == 1)
        {
            ll x;
            cin >> x;
            s.insert(x);
        }
        else if (a == 2)
        {
            ll x;
            cin >> x;
            auto it = s.find(x);
            if (it != s.end()) {
                s.erase(it); // Remove only one occurrence
            }
        }
        else if (a == 3)
        {
            // Count distinct integers currently in the bag
            set<ll> distinct(s.begin(), s.end());
            cout << distinct.size() << "\n";
        }
    }
}

int main()
{
    fastIO();
    Solve();
    return 0;
}