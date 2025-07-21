#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    set<int>st;
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int x;
            cin >> x;
            // If x is not in the set, insert it
            if (st.insert(x).second)
                cout << "Inserted " << x << endl;
        }
        else if (a == 2)
        {
            int y;
            cin >> y;
            // Remove y from the set
            st.erase(y);
        }
        else if (a == 3)
        {
            // Output the size of the set which represents the number of unique integers
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