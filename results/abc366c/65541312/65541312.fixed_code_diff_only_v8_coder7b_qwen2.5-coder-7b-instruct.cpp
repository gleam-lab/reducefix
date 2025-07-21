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
            st.insert(x); // Insert the element into the set
        }
        else if (a == 2)
        {
            int y;
            cin >> y;
            st.erase(st.find(y)); // Erase the element if it exists in the set
        }
        else if (a == 3)
        {
            cout << st.size() << endl; // Print the size of the set
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}