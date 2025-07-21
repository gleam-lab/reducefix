#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    unordered_map<int, int> cnt;
    int distinct = 0;

    rep(i, q)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;
            if (cnt[x] == 0)
                distinct++;
            cnt[x]++;
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            cnt[x]--;
            if (cnt[x] == 0)
                distinct--;
        }
        else if (type == 3)
        {
            cout << distinct << endl;
        }
    }

    return 0;
}