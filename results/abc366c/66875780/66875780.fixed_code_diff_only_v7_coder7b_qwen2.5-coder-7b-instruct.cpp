#include <iostream>
#include <set>

using namespace std;

// Typedefs for convenience
typedef long long ll;

// Fast IO
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
            s.erase(s.find(tp));
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
    
    int t = 1;
    while (t--)
    {
        Solve();
    }

    return 0;
}