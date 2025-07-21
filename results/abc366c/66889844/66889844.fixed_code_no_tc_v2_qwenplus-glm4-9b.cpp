#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> bag;

    for (int i = 0; i < n; i++) {
        int query;
        cin >> query;

        if (query == 1) {
            int value;
            cin >> value;
            bag.insert(value);
        } else if (query == 2) {
            int value;
            cin >> value;
            bag.erase(value);
        } else if (query == 3) {
            cout << bag.size() << endl;
        }
    }

    return 0;
}