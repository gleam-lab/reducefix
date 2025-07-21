#include <iostream>
#include <set>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    set<int> s; // Using set to maintain unique integers
    while (Q--) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            s.insert(x); // Insert the integer x into the set
        } else if (a == 2) {
            int x;
            cin >> x;
            s.erase(x); // Remove the integer x from the set
        } else if (a == 3) {
            cout << s.size() << "\n"; // Output the size of the set
        }
    }
    
    return 0;
}