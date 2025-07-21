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
            st.insert(x);
        }
        if (a == 2)
        {
            int y;
            cin >> y;
            st.erase(y);
        }
        if (a == 3)
        {
            cout << st.size() << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}