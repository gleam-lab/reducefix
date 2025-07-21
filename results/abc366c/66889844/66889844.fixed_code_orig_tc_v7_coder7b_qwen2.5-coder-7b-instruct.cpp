#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    multiset<int> mst;
    map<int, int> cnt;

    while(n--) {
        int type; cin >> type;
        if(type == 1) {
            int x; cin >> x;
            auto it = mst.find(x);
            if(it != end(mst)) {
                mst.erase(it);
                --cnt[x];
            }
            ++cnt[x];
            mst.insert(x);
        } else if(type == 2) {
            int x; cin >> x;
            ++cnt[x];
            mst.insert(x);
        } else if(type == 3) {
            cout << mst.size() << '\n';
        }
    }

    return 0;
}