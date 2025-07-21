#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int q;
    cin >> q;
    map<int, int> cnt;
    rep(i, q)
    {
        int type, x;
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            cnt[x]++;
        }
        else if (type == 2)
        {
            cin >> x;
            cnt[x]--;
            if (cnt[x] == 0)
                cnt.erase(x);
        }
        else if (type == 3)
        {
            cout << cnt.size() << endl;
        }
    }
}