#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    map<int, int> count_map; // Tracks count of each integer in the bag
    int distinct_count = 0;  // Number of distinct integers in the bag

    for (int i = 0; i < Q; ++i) {
        int type;
        cin >> type;

        if (type == 1 || type == 2) {
            int x;
            cin >> x;

            if (type == 1) {
                if (count_map[x] == 0) {
                    distinct_count++;
                }
                count_map[x]++;
            } else { // type == 2
                count_map[x]--;
                if (count_map[x] == 0) {
                    distinct_count--;
                }
            }
        } else if (type == 3) {
            cout << distinct_count << endl;
        }
    }

    return 0;
}