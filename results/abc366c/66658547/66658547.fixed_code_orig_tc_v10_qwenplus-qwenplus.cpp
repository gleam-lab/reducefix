#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> ballSet;
    map<int, int> countMap;
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            if (countMap[x] == 0) {
                ballSet.insert(x);
            }
            countMap[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            countMap[x]--;
            if (countMap[x] == 0) {
                ballSet.erase(x);
            }
        } else if (type == 3) {
            cout << ballSet.size() << "\n";
        }
    }

    return 0;
}