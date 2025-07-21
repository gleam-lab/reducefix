#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> m;
    int n = 0;
    int Q, type, x;

    cin >> Q;
    while (Q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            if (m.find(x) == m.end()) {
                m[x] = 1;
                n++;
            } else {
                m[x]++;
            }
        } else if (type == 2) {
            cin >> x;
            m[x]--;
            if (m[x] == 0) {
                m.erase(x);
                n--;
            }
        } else if (type == 3) {
            cout << n << endl;
        }
    }

    return 0;
}