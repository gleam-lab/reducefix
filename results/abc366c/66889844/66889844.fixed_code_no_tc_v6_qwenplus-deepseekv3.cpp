#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int Q; cin >> Q;
    map<int, int> count_map;
    int unique_count = 0;
    
    rep(i, Q) {
        int type; cin >> type;
        if (type == 1) {
            int x; cin >> x;
            count_map[x]++;
            if (count_map[x] == 1) {
                unique_count++;
            }
        } else if (type == 2) {
            int x; cin >> x;
            count_map[x]--;
            if (count_map[x] == 0) {
                unique_count--;
            }
        } else if (type == 3) {
            cout << unique_count << '\n';
        }
    }
}