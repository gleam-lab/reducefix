#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr int inf = 2000000000;
constexpr ll INF = 9200000000000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<int, int> count_map;
    int distinct_count = 0;
    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int x; cin >> x;
            if (count_map[x] == 0) {
                distinct_count++;
            }
            count_map[x]++;
        } else if (type == 2) {
            int x; cin >> x;
            count_map[x]--;
            if (count_map[x] == 0) {
                distinct_count--;
            }
        } else if (type == 3) {
            cout << distinct_count << "\n";
        }
    }
    return 0;
}