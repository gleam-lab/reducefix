#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    unordered_map<int, int> freq;
    int type, x;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            freq[x]++;
        } else if (type == 2) {
            cin >> x;
            freq[x]--;
            if (freq[x] == 0) {
                freq.erase(x); // Remove key if count is zero to free space
            }
        } else {
            cout << freq.size() << '\n';
        }
    }

    return 0;
}