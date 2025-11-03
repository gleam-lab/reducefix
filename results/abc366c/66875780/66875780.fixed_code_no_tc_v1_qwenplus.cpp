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
    multiset<ll> s; // Use multiset to allow duplicate values
    
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
            auto it = s.find(tp);
            if (it != s.end()) {
                s.erase(it); // Remove only one occurrence
            }
        }
        else // a == 3
        {
            // Count distinct elements by creating a set from the multiset
            // But we can just use the fact that we need unique values
            // We'll use a temporary set or better approach: maintain a separate frequency map
            
            // Actually, let's change approach: use map to track frequencies
            // But since we already started with multiset and problem is small,
            // we need to fix the logic. The current approach won't work because
            // set automatically removes duplicates.
        }
    }
}

// Let's completely rewrite with correct data structure
int main()
{
    fastIO();
    
    ll Q;
    cin >> Q;
    
    // Use a frequency map to keep track of count of each number
    map<ll, ll> freq;
    
    while (Q--)
    {
        ll type;
        cin >> type;
        
        if (type == 1)
        {
            ll x;
            cin >> x;
            freq[x]++;
        }
        else if (type == 2)
        {
            ll x;
            cin >> x;
            freq[x]--; // Remove one occurrence
            if (freq[x] == 0) {
                freq.erase(x); // Remove key when count becomes 0
            }
        }
        else // type == 3
        {
            cout << freq.size() << '\n';
        }
    }
    
    return 0;
}