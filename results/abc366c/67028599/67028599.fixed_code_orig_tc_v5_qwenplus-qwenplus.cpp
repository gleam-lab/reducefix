#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    unordered_map<int, int> count_map;
    int query_type, x;

    while (Q--) {
        cin >> query_type;
        if (query_type == 1) {
            cin >> x;
            count_map[x]++;
        } else if (query_type == 2) {
            cin >> x;
            count_map[x]--;
            if (count_map[x] == 0) {
                count_map.erase(x);
            }
        } else {
            cout << count_map.size() << '\n';
        }
    }

    return 0;
}