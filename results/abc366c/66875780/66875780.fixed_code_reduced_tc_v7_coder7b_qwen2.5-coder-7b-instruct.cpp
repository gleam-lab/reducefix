#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Q;
    cin >> Q;
    set<int> s;

    while (Q--) {
        int a;
        cin >> a;
        if (a == 1) {
            int tp;
            cin >> tp;
            s.insert(tp);
        } else if (a == 2) {
            int tp;
            cin >> tp;
            auto it = s.find(tp);
            if (it != s.end()) {
                s.erase(it);
            }
        } else {
            cout << s.size() << "\n";
        }
    }

    return 0;
}