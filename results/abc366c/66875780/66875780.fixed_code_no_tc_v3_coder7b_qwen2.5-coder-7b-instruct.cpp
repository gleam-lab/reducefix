#include <iostream>
#include <unordered_set>

using namespace std;

// Typedefs for convenience
typedef unordered_set<int> uset;

// Constants
const int INF = 1e9 + 7;

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
    uset s;
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

    // Your code here
    int t = 1;
    // cin >> t;
    while (t--)
    {
        // solve each test case
        Solve();
    }

    return 0;
}