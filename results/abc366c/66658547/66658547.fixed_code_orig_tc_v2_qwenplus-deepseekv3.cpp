#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr int inf = 2000000000;
constexpr ll INF = 9200000000000000000;

int main() {
    unordered_map<int, int> count;
    set<int> distinct;
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            count[x]++;
            if (count[x] == 1) {
                distinct.insert(x);
            }
        } else if (type == 2) {
            int x;
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                distinct.erase(x);
            }
        } else if (type == 3) {
            cout << distinct.size() << "\n";
        }
    }
    return 0;
}