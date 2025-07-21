#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            s.insert(x); // Inserting directly as we need unique elements only
        } else if (type == 2) {
            int x;
            cin >> x;
            s.erase(s.find(x)); // Erasing using find to ensure correct element removal
        } else if (type == 3) {
            cout << s.size() << endl; // Size of the set gives the number of unique elements
        }
    }

    return 0;
}