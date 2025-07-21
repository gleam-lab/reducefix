#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    map<int, int> freq;
    set<int> unique_vals;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            freq[x]++;
            unique_vals.insert(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0) {
                unique_vals.erase(x);
            }
        } else if (type == 3) {
            cout << unique_vals.size() << '\n';
        }
    }

    return 0;
}