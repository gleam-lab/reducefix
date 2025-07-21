#include <iostream>
#include <vector>
using namespace std;

const int MAX_X = 1000001; // Since x can go up to 10^6

int main() {
    int q, x;
    vector<int> cnt(MAX_X, 0); // Array to keep the count of each integer
    int uniqueInts = 0; // To keep track of the number of unique integers

    cin >> q;
    while (q--) {
        cin >> x;
        if (x == 1) { // Add
            cnt[x]++;
            if (cnt[x] == 1) {
                uniqueInts++;
            }
        } else if (x == 2) { // Remove
            cnt[x]--;
            if (cnt[x] == 0) {
                uniqueInts--;
            }
        } else if (x == 3) { // Query for unique count
            cout << uniqueInts << endl;
        }
    }

    return 0;
}