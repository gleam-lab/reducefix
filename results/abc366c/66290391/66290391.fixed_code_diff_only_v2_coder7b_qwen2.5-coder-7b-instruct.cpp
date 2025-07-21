#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;
    unordered_set<int> st;
    rep(i, q)
    {
        int type, x;
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            st.insert(x);
        }
        else if (type == 2)
        {
            cin >> x;
            st.erase(st.find(x));
        }
        else if (type == 3)
        {
            cout << st.size() << endl;
        }
    }
}