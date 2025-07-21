#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    set<int> st; // Using a set to store unique elements efficiently
    
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        
        if (a == 1)
        {
            int x;
            cin >> x;
            st.insert(x); // Insert element x into the set
        }
        else if (a == 2)
        {
            int y;
            cin >> y;
            st.erase(y); // Erase element y from the set
        }
        else if (a == 3)
        {
            cout << st.size() << endl; // Print the number of unique elements in the set
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
    while (t--)
    {
        solve();
    }

    return 0;
}