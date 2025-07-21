#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    unordered_map<int, int> counts;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            counts[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            counts[x]--;
            if (counts[x] == 0) {
                counts.erase(x);
            }
        } else if (type == 3) {
            cout << counts.size() << '\n';
        }
    }

    return 0;
}