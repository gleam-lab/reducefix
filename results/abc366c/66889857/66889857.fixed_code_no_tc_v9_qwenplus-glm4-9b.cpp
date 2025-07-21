#include <iostream>
#include <set>
using namespace std;

int main() {
    int q;
    cin >> q;
    
    set<int> bag;
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int number;
            cin >> number;
            bag.insert(number);
        } else if (type == 2) {
            int number;
            cin >> number;
            bag.erase(number);
        } else if (type == 3) {
            cout << bag.size() << endl;
        }
    }
    
    return 0;
}