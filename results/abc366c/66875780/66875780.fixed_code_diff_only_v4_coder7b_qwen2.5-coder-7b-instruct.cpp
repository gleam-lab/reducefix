#include <iostream>
#include <set>

using namespace std;

// Constants
const int MAX_Q = 2 * 100000;
const int MAX_X = 1000000;

// Fast IO
void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// Debug helper (optional)
#define debug(x) cerr << #x << " = " << x << "\n"

void Solve()
{
    int Q;
    cin >> Q;
    
    // Using a set to store unique elements
    set<int> s;
    
    while (Q--)
    {
        int a;
        cin >> a;
        
        if (a == 1)
        {
            int tp;
            cin >> tp;
            s.insert(tp);
        }
        else if (a == 2)
        {
            int tp;
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
    // Uncomment the line below to read multiple test cases
    // cin >> t;
    while (t--)
    {
        Solve();
    }
    
    return 0;
}