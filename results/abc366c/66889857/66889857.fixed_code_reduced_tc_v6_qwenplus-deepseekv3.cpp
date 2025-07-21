#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int Q; cin >> Q;
    unordered_map<int, int> count_map;
    set<int> distinct_elements;
    
    rep(i, Q) {
        int query_type; cin >> query_type;
        if (query_type == 1) {
            int x; cin >> x;
            count_map[x]++;
            if (count_map[x] == 1) {
                distinct_elements.insert(x);
            }
        } else if (query_type == 2) {
            int x; cin >> x;
            count_map[x]--;
            if (count_map[x] == 0) {
                distinct_elements.erase(x);
            }
        } else if (query_type == 3) {
            cout << distinct_elements.size() << '\n';
        }
    }
    
    return 0;
}