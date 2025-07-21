#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    unordered_map<int, int> countMap;  // To keep track of counts of each integer
    int distinctCount = 0;             // Number of distinct integers

    int type, x;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            if (countMap[x] == 0) {
                distinctCount++;
            }
            countMap[x]++;
        } else if (type == 2) {
            cin >> x;
            countMap[x]--;
            if (countMap[x] == 0) {
                distinctCount--;
            }
        } else {
            cout << distinctCount << endl;
        }
    }

    return 0;
}