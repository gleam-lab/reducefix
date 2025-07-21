#include <iostream>
#include <set>
using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> s;
    while(q--) {
        int t, x;
        cin >> t;
        if(t == 1) {
            cin >> x;
            s.insert(x);
        } else if(t == 2) {
            cin >> x;
            s.erase(s.find(x));
        } else {
            cout << s.size() << '\n';
        }
    }
    return 0;
}