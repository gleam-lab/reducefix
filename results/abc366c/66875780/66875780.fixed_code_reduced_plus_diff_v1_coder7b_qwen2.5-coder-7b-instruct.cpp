#include <iostream>
#include <unordered_set>
#include <multiset>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unordered_set<int> uniqueElements; // To store unique elements
    multiset<int> allElements; // To store all elements

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int value;
            cin >> value;
            uniqueElements.insert(value); // Insert into unique set
            allElements.insert(value); // Insert into all elements set
        } else if (type == 2) {
            int value;
            cin >> value;
            uniqueElements.erase(uniqueElements.find(value)); // Erase from unique set
            allElements.erase(allElements.find(value)); // Erase from all elements set
        } else {
            cout << uniqueElements.size() << '\n'; // Output size of unique set
        }
    }

    return 0;
}