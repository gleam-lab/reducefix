#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> m;
    int q;
    cin >> q;

    int ans = 0;
    for (int i = 0; i < q; ++i) {
        int n, x;
        cin >> n;

        if (n == 1) {
            cin >> x;
            m[x]++;
            if (m[x] == 1) { // Only increment ans if this is the first occurrence of x
                ans++;
            }
        } else if (n == 2) {
            cin >> x;
            m[x]--;
            if (m[x] == 0) { // Only decrement ans if this was the last occurrence of x
                ans--;
            }
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}