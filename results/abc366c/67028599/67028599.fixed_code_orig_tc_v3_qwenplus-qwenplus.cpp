#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    unordered_map<int, int> count;
    int type, x;

    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            count[x]++;
        } else if (type == 2) {
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                count.erase(x);
            }
        } else {
            cout << count.size() << '\n';
        }
    }

    return 0;
}