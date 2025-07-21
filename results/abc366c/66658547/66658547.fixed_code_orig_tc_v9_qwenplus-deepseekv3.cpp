#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<int, int> count_map;
    int distinct_count = 0;
    int q;
    cin >> q;
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            if (count_map[x] == 0) {
                distinct_count++;
            }
            count_map[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            if (count_map[x] > 0) {
                count_map[x]--;
                if (count_map[x] == 0) {
                    distinct_count--;
                }
            }
        } else if (type == 3) {
            cout << distinct_count << "\n";
        }
    }
    
    return 0;
}