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
    
    // Use map to count frequency of each number
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
            // Remove the key if count becomes 0
            if (freq[x] == 0) {
                freq.erase(x);
            }
        }
        else
        {
            // The number of distinct integers is the size of the map
            cout << freq.size() << "\n";
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