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
    set<ll> s;
    while (Q--)
    {
        ll a;
        cin >> a;
        if (a == 1)
        {
            ll tp;
            cin >> tp;
            s.insert(tp);
        }
        else if (a == 2)
        {
            ll tp;
            cin >> tp;
            s.erase(tp);
        }
        else
        {
            cout << s.size() << "\n";
        }
    }
}

int main()
{
    fastIO();
    Solve();
    return 0;
}