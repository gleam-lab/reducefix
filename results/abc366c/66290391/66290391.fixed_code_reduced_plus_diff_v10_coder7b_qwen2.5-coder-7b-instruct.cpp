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
    map<int, int> mp;
    set<int> s;

    while (q--) {
        int type, x;
        cin >> type;
        if (type == 1) {
            cin >> x;
            if (mp[x] == 0) {
                s.insert(x);
            }
            mp[x]++;
        } else if (type == 2) {
            cin >> x;
            mp[x]--;
            if (mp[x] == 0) {
                s.erase(s.find(x));
            }
        } else {
            cout << s.size() << '\n';
        }
    }

    return 0;
}