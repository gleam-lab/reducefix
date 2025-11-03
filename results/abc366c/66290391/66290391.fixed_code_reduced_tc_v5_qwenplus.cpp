#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int q;
    cin >> q;
    map<int, int> count;
    set<int> distinct;
    
    rep(i, q)
    {
        int type, x;
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            count[x]++;
            distinct.insert(x);
        }
        else if (type == 2)
        {
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                distinct.erase(x);
            }
        }
        else if (type == 3)
        {
            cout << distinct.size() << endl;
        }
    }
}