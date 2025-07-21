#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    set<int>st;
    while (q--)
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