#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int q;
    cin >> q;
    unordered_set<int> st; // Use unordered_set for faster operations
    rep(i, q)
    {
        int type, x;
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            st.insert(x);
        }
        else if (type == 2) // Corrected else if condition
        {
            cin >> x;
            st.erase(st.find(x)); // Ensure x exists before erasing
        }
        else if (type == 3)
        {
            cout << st.size() << endl;
        }
    }
}