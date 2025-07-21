#include <iostream>
#include <set>

using namespace std;

int main() {
    int q;
    cin >> q;

    set<int> balls;
    int type, x;

    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            balls.insert(x);
        } else if (type == 2) {
            cin >> x;
            balls.erase(x);
        } else {
            cout << balls.size() << endl;
        }
    }

    return 0;
}