#include <iostream>
#include <set>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    set<int> a;
    int queryType, x;
    
    while (Q--) {
        cin >> queryType;
        if (queryType == 1) {
            cin >> x;
            a.insert(x);
        } else if (queryType == 2) {
            cin >> x;
            a.erase(x);
        } else if (queryType == 3) {
            cout << a.size() << endl;
        }
    }
    
    return 0;
}