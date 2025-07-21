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
    map<int, int> mp;
    while(q--) {
        int type, x;
        cin >> type;
        if(type == 1) {
            cin >> x;
            mp[x]++;
        } else if(type == 2) {
            cin >> x;
            mp[x]--;
            if(mp[x] == 0) mp.erase(x);
        } else if(type == 3) {
            cout << mp.size() << '\n';
        }
    }
    return 0;
}