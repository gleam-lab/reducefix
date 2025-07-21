#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, int> m;
    int Q;
    cin >> Q;
    int n = 0;
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            if (m[x] == 0) {
                n++;
            }
            m[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            m[x]--;
            if (m[x] == 0) {
                n--;
            }
        } else if (type == 3) {
            cout << n << endl;
        }
    }
    return 0;
}