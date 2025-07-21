#include <iostream>
#include <set>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    set<int> s;
    
    while (Q--) {
        int query;
        cin >> query;
        if (query == 1) {
            int value;
            cin >> value;
            s.insert(value);
        } else if (query == 2) {
            int value;
            cin >> value;
            s.erase(value);
        } else if (query == 3) {
            cout << s.size() << endl;
        }
    }
    
    return 0;
}