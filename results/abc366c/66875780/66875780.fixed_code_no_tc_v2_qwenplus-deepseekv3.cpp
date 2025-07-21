#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Solve() {
    int Q;
    cin >> Q;
    unordered_map<int, int> count_map;
    int distinct_count = 0;
    
    while (Q--) {
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
            count_map[x]--;
            if (count_map[x] == 0) {
                distinct_count--;
            }
        } else {
            cout << distinct_count << "\n";
        }
    }
}

int main() {
    fastIO();
    Solve();
    return 0;
}