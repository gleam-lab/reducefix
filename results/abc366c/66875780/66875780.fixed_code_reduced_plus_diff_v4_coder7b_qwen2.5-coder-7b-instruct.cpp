#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Constants
const int MAXN = 1e6 + 10;

// Data structure to store the counts of numbers
unordered_set<int> bag;

// Function to handle the first type of query
void insert(int x) {
    bag.insert(x);
}

// Function to handle the second type of query
void remove(int x) {
    bag.erase(bag.find(x));
}

// Function to handle the third type of query
void countDistinctNumbers() {
    cout << bag.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;
    
    while (Q--) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            insert(x);
        } else if (a == 2) {
            int x;
            cin >> x;
            remove(x);
        } else {
            countDistinctNumbers();
        }
    }

    return 0;
}