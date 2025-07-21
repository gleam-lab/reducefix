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
    set<int> st;
    while(q--) // Changed loop condition to use while loop for better performance
    {
        int type, x;
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            st.insert(x);
        }
        else if (type == 2) // Used else if for better readability and performance
        {
            cin >> x;
            st.erase(st.find(x)); // Corrected erase method usage
        }
        else if (type == 3)
        {
            cout << st.size() << '\n'; // Used '\n' instead of endl for better performance
        }
    }
    return 0;
}