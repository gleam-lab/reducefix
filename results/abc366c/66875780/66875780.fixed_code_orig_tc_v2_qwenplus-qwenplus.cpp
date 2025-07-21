#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    unordered_map<int, int> countMap; // Tracks how many times each number appears
    set<int> uniqueSet;              // Tracks the unique numbers currently in the bag

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            countMap[x]++;
            if (countMap[x] == 1) {
                uniqueSet.insert(x);
            }
        } else if (type == 2) {
            int x;
            cin >> x;
            countMap[x]--;
            if (countMap[x] == 0) {
                uniqueSet.erase(x);
            }
        } else { // type == 3
            cout << uniqueSet.size() << "\n";
        }
    }

    return 0;
}