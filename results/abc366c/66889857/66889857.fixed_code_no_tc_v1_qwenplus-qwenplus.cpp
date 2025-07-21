#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    map<int, int> countMap;  // To keep track of counts of each number
    int distinctCount = 0;   // Number of distinct integers in the bag

    while (Q--) {
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
        else {  // type == 3
            cout << distinctCount << endl;
        }
    }

    return 0;
}