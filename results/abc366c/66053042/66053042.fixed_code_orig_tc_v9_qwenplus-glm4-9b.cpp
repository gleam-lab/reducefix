#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> m;
    int Q;
    cin >> Q;
    int unique_count = 0;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            if (m.find(x) == m.end()) {
                unique_count++;
            }
            m[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            if (--m[x] == 0) {
                unique_count--;
            }
        } else if (type == 3) {
            cout << unique_count << endl;
        }
    }
    return 0;
}