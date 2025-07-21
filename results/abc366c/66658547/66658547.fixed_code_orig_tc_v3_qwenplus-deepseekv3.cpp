#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, int> freq;
    set<int> unique;
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            freq[x]++;
            if (freq[x] == 1) {
                unique.insert(x);
            }
        } else if (type == 2) {
            int x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0) {
                unique.erase(x);
            }
        } else if (type == 3) {
            cout << unique.size() << "\n";
        }
    }
    return 0;
}