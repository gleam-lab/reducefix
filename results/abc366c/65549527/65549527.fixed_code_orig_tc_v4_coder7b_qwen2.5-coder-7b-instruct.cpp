#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    set<int> st;
    map<int,int> count;
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int x;
            cin >> x;
            if(count[x] > 0){
                st.erase(st.find(x));
            }
            st.insert(x);
            count[x]++;
        }
        else if (a == 2)
        {
            int y;
            cin >> y;
            if(count[y] > 0){
                st.erase(st.find(y));
                count[y]--;
            }
        }
        else
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