#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    set<int> s;

    for (int i = 0; i < Q; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            s.insert(x);
        } else if (op == 2) {
            int x;
            cin >> x;
            s.erase(x);
        } else {
            cout << s.size() << '\n';
        }
    }

    return 0;
}