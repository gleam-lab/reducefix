#include <iostream>
#include <map>
using namespace std;

int main() {
    int q;
    cin >> q;

    map<int, int> m; // To keep track of the count of each ball
    int ans = 0; // To keep track of the number of unique balls
    while (q--) {
        int n, x;
        cin >> n;
        if (n == 1) {
            cin >> x;
            if (m[x] == 0) { // Only increment ans if the ball is added for the first time
                ans++;
            }
            m[x]++;
        } else if (n == 2) {
            cin >> x;
            m[x]--;
            if (m[x] == 0) { // Only decrement ans if the last ball of this type is removed
                ans--;
            }
        } else if (n == 3) {
            cout << ans << endl;
        }
    }
    return 0;
}