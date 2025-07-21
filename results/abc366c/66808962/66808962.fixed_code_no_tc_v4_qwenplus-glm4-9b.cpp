#include <iostream>
#include <map>

using namespace std;

int main() {
    int q;
    cin >> q;
    map<int, int> m;
    int ans = 0;

    for (int i = 0; i < q; i++) {
        int n, x;
        cin >> n;

        if (n == 1) { // Add ball x to the bag
            cin >> x;
            m[x]++; // Increment the count of this ball
            if (m[x] == 1) { // If this is the first ball with number x, increment the answer
                ans++;
            }
        } else if (n == 2) { // Remove ball x from the bag
            cin >> x;
            m[x]--; // Decrement the count of this ball
            if (m[x] == 0) { // If this ball is now exhausted (count is 0), decrement the answer
                ans--;
            }
        } else if (n == 3) { // Output the number of different balls
            cout << ans << endl;
        }
    }

    return 0;
}