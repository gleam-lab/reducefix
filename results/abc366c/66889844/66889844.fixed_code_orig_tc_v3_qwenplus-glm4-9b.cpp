#include <iostream>
#include <set>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    set<int> a;
    
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        
        if (x == 1 || x == 2) {
            int y;
            cin >> y;
            if (x == 1) {
                a.insert(y);
            } else {
                a.erase(y);
            }
        } else if (x == 3) {
            cout << a.size() << endl;
        }
    }
    
    return 0;
}