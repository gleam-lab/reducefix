#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a)
        cin >> tt;
    for (auto &tt : b)
        cin >> tt;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // We will use a pointer approach to match toys to boxes
    int i = 0, j = 0;
    int x = -1;

    while (i < n && j < n - 1)
    {
        if (a[i] <= b[j])
        {
            // Toy fits in the box, move both pointers
            ++i;
            ++j;
        }
        else
        {
            // Toy doesn't fit, we need a special box for it
            if (x == -1)
            {
                x = a[i];
                ++i; // This toy is placed in our special box
            }
            else
            {
                // Already have a special box needed, can't satisfy requirements
                cout << -1 << endl;
                return;
            }
        }
    }

    // If we still have toys left after processing all boxes
    if (i < n)
    {
        if (x == -1)
            x = a[i]; // Need one more box for the smallest remaining toy
        else
        {
            cout << -1 << endl;
            return;
        }
    }

    cout << x << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}