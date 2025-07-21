#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    unordered_map<int, int> countMap; // Tracks count of each number in the bag
    int distinctCount = 0; // Tracks the number of distinct integers

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1 || type == 2) {
            int x;
            cin >> x;

            if (type == 1) {
                if (countMap[x] == 0) {
                    distinctCount++;
                }
                countMap[x]++;
            } else { // type == 2
                countMap[x]--;
                if (countMap[x] == 0) {
                    distinctCount--;
                }
            }
        } else if (type == 3) {
            cout << distinctCount << "\n";
        }
    }

    return 0;
}