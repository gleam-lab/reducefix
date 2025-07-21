#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    unordered_set<int> s;
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
            s.erase(tp);
        } else {
            cout << s.size() << "\n";
        }
    }
    return 0;
}