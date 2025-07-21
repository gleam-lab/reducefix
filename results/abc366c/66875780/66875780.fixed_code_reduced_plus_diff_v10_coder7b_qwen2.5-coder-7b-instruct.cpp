#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> s;
    int q;
    cin >> q;
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int val;
            cin >> val;
            s.insert(val);
        } else if(type == 2) {
            int val;
            cin >> val;
            s.erase(s.find(val));
        } else {
            cout << s.size() << '\n';
        }
    }
    return 0;
}