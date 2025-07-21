#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> m;
    int q;
    cin >> q;
    int ans = 0;

    for (int i = 0; i < q; ++i) {
        int type, x;
        cin >> type;

        if (type == 1) {
            cin >> x;
            if (m[x] == 0) {
                ans++;
            }
            m[x]++;
        } else if (type == 2) {
            cin >> x;
            m[x]--;
            if (m[x] == 0) {
                ans--;
            }
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}