#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    unordered_set<int> uniqueIntegers;
    int uniqueCount = 0;

    while (Q--) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int x;
            cin >> x;
            uniqueIntegers.insert(x);
            if (++uniqueCount != uniqueIntegers.size()) {
                uniqueIntegers.erase(uniqueIntegers.find(uniqueCount - 1));
            }
        } else if (queryType == 2) {
            int x;
            cin >> x;
            uniqueIntegers.erase(x);
            uniqueCount--;
        } else if (queryType == 3) {
            cout << uniqueCount << endl;
        }
    }

    return 0;
}