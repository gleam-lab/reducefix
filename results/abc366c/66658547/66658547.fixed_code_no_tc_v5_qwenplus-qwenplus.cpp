#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, int> counts;
    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            counts[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            counts[x]--;
            if (counts[x] == 0) {
                counts.erase(x);
            }
        } else if (type == 3) {
            cout << counts.size() << "\n";
        }
    }
}