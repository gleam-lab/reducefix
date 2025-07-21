#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, int> m;  // Map to keep track of the count of each integer
    int q;
    cin >> q;  // Read the number of queries

    int ans = 0;  // This holds the number of unique integers in the bag
    for (int i = 0; i < q; i++) {
        int n, x;
        cin >> n;  // Read the type of query

        if (n == 1) {
            cin >> x;
            m[x]++;  // Increment the count for integer x
            if (m[x] == 1) ans++;  // Increment the count of unique integers if x was not present before
        } else if (n == 2) {
            cin >> x;
            m[x]--;  // Decrement the count for integer x
            if (m[x] == 0) ans--;  // Decrement the count of unique integers if x is now gone
        } else if (n == 3) {
            cout << ans << endl;  // Output the number of unique integers
        }
    }

    return 0;
}