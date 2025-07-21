#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> m; // Map to store the count of each integer in the bag
    int n = 0; // Number of different integers in the bag

    int Q;
    cin >> Q; // Number of queries

    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type; // Type of query

        if (type == 1) {
            int x;
            cin >> x; // Integer to be added to the bag

            if (m.count(x) == 0) {
                n++; // Increase the count of different integers
            }
            m[x]++; // Increase the count of the integer x in the bag
        } else if (type == 2) {
            int x;
            cin >> x; // Integer to be removed from the bag

            if (--m[x] == 0) {
                n--; // Decrease the count of different integers if this is the last occurrence
            }
        } else if (type == 3) {
            cout << n << endl; // Output the number of different integers
        }
    }

    return 0;
}