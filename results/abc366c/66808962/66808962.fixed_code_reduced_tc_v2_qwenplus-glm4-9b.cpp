#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> m; // To keep track of the count of each ball
    int q;
    cin >> q;

    int ans = 0; // To count the number of different integers
    for (int i = 0; i < q; i++) {
        int n, x;
        cin >> n;

        if (n == 1) {
            cin >> x;
            m[x]++; // Increment the count of ball with integer x
            if (m[x] == 1) { // If it's the first time this integer is being added
                ans++;
            }
        } else if (n == 2) {
            cin >> x;
            m[x]--; // Decrement the count of ball with integer x
            if (m[x] == 0) { // If it's the last ball of this integer
                ans--;
            }
        } else {
            cout << ans << endl; // Output the number of different integers
        }
    }
    return 0;
}