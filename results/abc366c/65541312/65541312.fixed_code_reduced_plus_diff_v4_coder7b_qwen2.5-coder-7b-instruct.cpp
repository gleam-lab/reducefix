#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    unordered_set<int> st;
    int addCount = 0, removeCount = 0;
    
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int x;
            cin >> x;
            if(st.find(x) == st.end()) { // Check if the element is already present
                st.insert(x);
                addCount++;
            }
        }
        else if (a == 2)
        {
            int y;
            cin >> y;
            if(st.find(y) != st.end()) { // Check if the element exists before removing
                st.erase(y);
                removeCount++;
            }
        }
        else if (a == 3)
        {
            cout << addCount - removeCount << endl;
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