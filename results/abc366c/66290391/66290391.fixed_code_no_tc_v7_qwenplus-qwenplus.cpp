#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    unordered_map<int, int> counts;
    int uniqueCount = 0;

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            if (counts[x] == 0) {
                ++uniqueCount;
            }
            ++counts[x];
        } else if (type == 2) {
            int x;
            cin >> x;
            --counts[x];
            if (counts[x] == 0) {
                --uniqueCount;
            }
        } else if (type == 3) {
            cout << uniqueCount << endl;
        }
    }

    return 0;
}