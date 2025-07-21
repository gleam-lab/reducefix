#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    set<int> st;
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int x;
            cin >> x;
            st.insert(x); // Corrected variable name 'x' instead of 'y'
        }
        else if (a == 2) // Added else if condition to avoid multiple checks
        {
            int y;
            cin >> y;
            st.erase(y);
        }
        else if (a == 3) // Added else if condition to avoid multiple checks
        {
            cout << st.size() << endl;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}