#include <iostream>
#include <map>
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
    map<ll, ll> freq;
    
    while (Q--)
    {
        ll a;
        cin >> a;
        if (a == 1)
        {
            ll x;
            cin >> x;
            freq[x]++;
        }
        else if (a == 2)
        {
            ll x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0) {
                freq.erase(x);
            }
        }
        else
        {
            cout << freq.size() << "\n";
        }
    }
}

int main()
{
    fastIO();
    Solve();
    return 0;
}