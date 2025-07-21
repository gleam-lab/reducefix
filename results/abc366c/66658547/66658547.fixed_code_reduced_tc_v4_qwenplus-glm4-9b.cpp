#include <iostream>
#include <set>
using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> balls;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            balls.insert(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            balls.erase(x);
        } else if (type == 3) {
            cout << balls.size() << '\n';
        }
    }
    return 0;
}