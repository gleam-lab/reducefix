#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    unordered_map<int, int> count_map; // Tracks count of each number
    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            count_map[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            count_map[x]--;
            if (count_map[x] == 0) {
                count_map.erase(x); // Remove key if count becomes zero
            }
        } else {
            cout << count_map.size() << '\n';
        }
    }

    return 0;
}