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
    multiset<ll> s; // Use multiset instead of set to allow duplicate values
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
            auto it = s.find(tp); // Find one occurrence
            if (it != s.end()) {
                s.erase(it); // Erase only one occurrence
            }
        }
        else
        {
            // Count distinct elements by creating a set from the multiset or use a separate frequency map
            // But we can simply use a separate map to track frequencies for efficiency
            // However, since we already changed logic, let's fix with better approach below.
        }
    }
}

// Reworked solution using frequency map for correctness and efficiency
int main()
{
    fastIO();

    ll Q;
    cin >> Q;
    
    unordered_map<ll, ll> freq; // Frequency count for each number
    ll distinct = 0; // Current count of distinct integers
    
    while (Q--)
    {
        ll type;
        cin >> type;
        
        if (type == 1)
        {
            ll x;
            cin >> x;
            if (freq[x] == 0) {
                distinct++;
            }
            freq[x]++;
        }
        else if (type == 2)
        {
            ll x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0) {
                distinct--;
            }
        }
        else // type == 3
        {
            cout << distinct << '\n';
        }
    }

    return 0;
}