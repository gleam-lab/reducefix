#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    unordered_map<int, int> freq;
    set<int> st;
    rep(i, q)
    {
        int type, x;
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            freq[x]++;
            if (freq[x] == 1)
                st.insert(x);
        }
        else if (type == 2)
        {
            cin >> x;
            freq[x]--;
            if (freq[x] == 0)
                st.erase(x);
        }
        else if (type == 3)
        {
            cout << st.size() << '\n';
        }
    }
    return 0;
}