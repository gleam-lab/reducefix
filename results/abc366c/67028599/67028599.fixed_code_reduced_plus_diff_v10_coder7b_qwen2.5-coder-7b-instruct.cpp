#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    unordered_map<int, int> countMap;
    set<int> distinctElements;

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            if (countMap[x] == 0) {
                distinctElements.insert(x);
            }
            countMap[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            if (countMap[x] > 0) {
                countMap[x]--;
                if (countMap[x] == 0) {
                    distinctElements.erase(x);
                }
            }
        } else {
            cout << distinctElements.size() << endl;
        }
    }

    return 0;
}