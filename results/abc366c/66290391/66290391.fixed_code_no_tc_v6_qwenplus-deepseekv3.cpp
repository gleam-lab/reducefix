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
    int distinct = 0;
    rep(i, q)
    {
        int type, x;
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            if (count[x] == 0) {
                distinct++;
            }
            count[x]++;
        }
        else if (type == 2)
        {
            cin >> x;
            if (count[x] == 1) {
                distinct--;
            }
            count[x]--;
        }
        else if (type == 3)
        {
            cout << distinct << '\n';
        }
    }
    return 0;
}