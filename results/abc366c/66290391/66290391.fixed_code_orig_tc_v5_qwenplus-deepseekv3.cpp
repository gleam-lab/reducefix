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
    unordered_map<int, int> count;
    int unique = 0;
    
    rep(i, q)
    {
        int type;
        cin >> type;
        
        if (type == 1)
        {
            int x;
            cin >> x;
            if (count[x] == 0) unique++;
            count[x]++;
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            count[x]--;
            if (count[x] == 0) unique--;
        }
        else if (type == 3)
        {
            cout << unique << '\n';
        }
    }
}