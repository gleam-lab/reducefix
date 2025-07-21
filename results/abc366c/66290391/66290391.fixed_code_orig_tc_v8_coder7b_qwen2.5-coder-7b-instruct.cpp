#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    map<int, int> mp;

    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        else if(type == 2)
        {
            int x;
            cin >> x;
            if(mp.find(x) != mp.end())
                mp[x]--;
            if(mp[x] == 0)
                mp.erase(x);
        }
        else if(type == 3)
        {
            cout << mp.size() << "\n";
        }
    }

    return 0;
}