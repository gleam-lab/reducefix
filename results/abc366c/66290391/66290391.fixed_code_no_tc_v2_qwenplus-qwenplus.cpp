#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    map<int, int> countMap; // To keep track of counts of each number
    int distinctCount = 0;  // To store current number of distinct integers

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;

        if (type == 1 || type == 2) {
            int x;
            cin >> x;

            if (type == 1) {
                if (countMap[x] == 0) {
                    ++distinctCount;
                }
                ++countMap[x];
            } else { // type == 2
                --countMap[x];
                if (countMap[x] == 0) {
                    --distinctCount;
                }
            }
        } else { // type == 3
            cout << distinctCount << endl;
        }
    }

    return 0;
}