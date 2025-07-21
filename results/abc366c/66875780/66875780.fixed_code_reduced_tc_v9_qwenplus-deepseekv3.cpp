#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void Solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Q;
    cin >> Q;
    unordered_map<int, int> count;
    unordered_set<int> distinct;

    while (Q--) {
        int query_type;
        cin >> query_type;

        if (query_type == 1) {
            int x;
            cin >> x;
            count[x]++;
            if (count[x] == 1) {
                distinct.insert(x);
            }
        } else if (query_type == 2) {
            int x;
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                distinct.erase(x);
            }
        } else if (query_type == 3) {
            cout << distinct.size() << "\n";
        }
    }
}

int main() {
    Solve();
    return 0;
}