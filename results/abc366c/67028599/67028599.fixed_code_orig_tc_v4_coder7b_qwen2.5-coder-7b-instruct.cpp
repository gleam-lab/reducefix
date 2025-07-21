#include <iostream>
#include <set>

using namespace std;

int main() {
    int q;
    cin >> q;

    set<int> bag;

    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int x;
            cin >> x;
            bag.insert(x);
        } else if(type == 2) {
            int x;
            cin >> x;
            bag.erase(bag.find(x));
        } else {
            cout << bag.size() << '\n';
        }
    }

    return 0;
}