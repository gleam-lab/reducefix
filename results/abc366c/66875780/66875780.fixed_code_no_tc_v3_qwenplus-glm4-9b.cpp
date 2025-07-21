#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    unordered_set<int> bag;
    
    while (Q--) {
        int a;
        cin >> a;
        
        if (a == 1) {
            int x;
            cin >> x;
            bag.insert(x);
        } else if (a == 2) {
            int x;
            cin >> x;
            bag.erase(x);
        } else if (a == 3) {
            cout << bag.size() << '\n';
        }
    }
    
    return 0;
}