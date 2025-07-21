#include<iostream>
#include<map>
using namespace std;

int main() {
    map<int, int> m;
    int q;
    cin >> q;
    int ans = 0;

    for (int i = 0; i < q; i++) {
        int n, x;
        cin >> n;

        if (n == 1) {
            cin >> x;
            m[x]++;
            if (m[x] == 1) { // Only increment ans if it was zero before adding
                ans++;
            }
        } else if (n == 2) {
            cin >> x;
            m[x]--;
            if (m[x] == 0) { // Only decrement ans if it's now zero
                ans--;
            }
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}