#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int Q; cin >> Q;
    unordered_map<int, int> count_map;
    int distinct_count = 0;
    
    rep(i, Q) {
        int query_type; cin >> query_type;
        if (query_type == 1) {
            int x; cin >> x;
            if (count_map[x] == 0) {
                distinct_count++;
            }
            count_map[x]++;
        } else if (query_type == 2) {
            int x; cin >> x;
            count_map[x]--;
            if (count_map[x] == 0) {
                distinct_count--;
                count_map.erase(x);
            }
        } else if (query_type == 3) {
            cout << distinct_count << endl;
        }
    }
    return 0;
}