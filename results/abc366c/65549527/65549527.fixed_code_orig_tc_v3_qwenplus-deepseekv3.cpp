#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int q;
    cin >> q;
    unordered_map<int, int> count;
    set<int> distinct;
    
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        
        if (type == 1)
        {
            int x;
            cin >> x;
            count[x]++;
            if (count[x] == 1) {
                distinct.insert(x);
            }
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            if (count[x] > 0) {
                count[x]--;
                if (count[x] == 0) {
                    distinct.erase(x);
                }
            }
        }
        else if (type == 3)
        {
            cout << distinct.size() << endl;
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