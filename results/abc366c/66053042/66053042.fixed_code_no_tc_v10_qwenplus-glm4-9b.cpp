#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> m;  // To store the count of each ball
    int Q;            // Number of queries

    cin >> Q;  // Read the number of queries
    while (Q--) {  // Process each query
        int type;
        cin >> type;  // Read the type of the query

        if (type == 1) {
            int x;
            cin >> x;  // Read the value of the ball
            m[x]++;    // Increment the count of this ball
        } else if (type == 2) {
            int x;
            cin >> x;  // Read the value of the ball to be removed
            m[x]--;  // Decrement the count of this ball
            if (m[x] == 0) m.erase(x);  // Remove the ball if its count is zero
        } else if (type == 3) {
            cout << m.size() << endl;  // Output the number of different integers
        }
    }

    return 0;
}