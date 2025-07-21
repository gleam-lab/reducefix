#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    multiset<int> balls;
    map<int, int> count_map;

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            count_map[x]++;
        } 
        else if (type == 2) {
            int x;
            cin >> x;
            count_map[x]--;
            if (count_map[x] == 0) {
                count_map.erase(x);
            }
        } 
        else if (type == 3) {
            cout << count_map.size() << "\n";
        }
    }

    return 0;
}