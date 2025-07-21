#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    
    map<int, int> ballCount; // Tracks the count of each integer in the bag
    set<int> uniqueIntegers; // Tracks the unique integers currently in the bag

    while (q--) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int x;
            cin >> x;
            if (ballCount[x] == 0) {
                uniqueIntegers.insert(x);
            }
            ballCount[x]++;
        } 
        else if (queryType == 2) {
            int x;
            cin >> x;
            ballCount[x]--;
            if (ballCount[x] == 0) {
                uniqueIntegers.erase(x);
            }
        } 
        else if (queryType == 3) {
            cout << uniqueIntegers.size() << "\n";
        }
    }

    return 0;
}