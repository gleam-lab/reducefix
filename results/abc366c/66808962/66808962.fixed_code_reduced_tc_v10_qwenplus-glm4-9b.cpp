#include <iostream>
#include <map>
using namespace std;

int main() {
    int q;
    cin >> q;
    map<int, int> m;
    int ans = 0;

    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;
        if (n == 1) {
            int x;
            cin >> x;
            m[x]++;
            if (m[x] == 1) {
                ans++;
            }
        } else if (n == 2) {
            int x;
            cin >> x;
            m[x]--;
            if (m[x] == 0) {
                ans--;
            }
        } else if (n == 3) {
            cout << ans << endl;
        }
    }

    return 0;
}