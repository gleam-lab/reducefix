#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    unordered_map<int, int> countMap; // Tracks count of each integer in the bag
    int distinctCount = 0; // Number of distinct integers

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            if (countMap[x] == 0) {
                distinctCount++;
            }
            countMap[x]++;
        } 
        else if (type == 2) {
            int x;
            cin >> x;
            countMap[x]--;
            if (countMap[x] == 0) {
                distinctCount--;
            }
        } 
        else { // type == 3
            cout << distinctCount << endl;
        }
    }

    return 0;
}