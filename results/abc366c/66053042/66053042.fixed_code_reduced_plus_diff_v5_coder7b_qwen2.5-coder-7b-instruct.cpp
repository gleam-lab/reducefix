#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<int> s; // Set to store unique elements
    unordered_map<int, int> m; // Map to store count of each element

    int Q;
    cin >> Q;
    
    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            if (m.find(x) != m.end()) {
                m[x]++;
            } else {
                s.insert(x);
                m[x] = 1;
            }
        } else if (type == 2) {
            int x;
            cin >> x;
            if (m.find(x) != m.end()) {
                m[x]--;
                if (m[x] == 0) {
                    s.erase(x);
                }
            }
        } else if (type == 3) {
            cout << s.size() << '\n';
        }
    }

    return 0;
}