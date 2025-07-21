#include <iostream>
#include <set>
using namespace std;

int main() {
    int q;
    cin >> q;
    multiset<int> s;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int val;
            cin >> val;
            s.insert(val);
        } else if (type == 2) {
            int val;
            cin >> val;
            s.erase(s.find(val));
        } else {
            cout << s.size() << endl;
        }
    }
    return 0;
}