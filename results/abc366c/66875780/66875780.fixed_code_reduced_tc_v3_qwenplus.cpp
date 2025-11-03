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
    multiset<ll> bag;
    while (Q--)
    {
        ll a;
        cin >> a;
        if (a == 1)
        {
            ll x;
            cin >> x;
            bag.insert(x);
        }
        else if (a == 2)
        {
            ll x;
            cin >> x;
            auto it = bag.find(x);
            if (it != bag.end())
            {
                bag.erase(it);
            }
        }
        else
        {
            set<ll> distinct(bag.begin(), bag.end());
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