#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;
    set<int> s;

    while(Q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int x;
            cin >> x;
            s.insert(x);
        } else if(type == 2) {
            int x;
            cin >> x;
            s.erase(s.find(x));
        } else {
            cout << s.size() << endl;
        }
    }

    return 0;
}