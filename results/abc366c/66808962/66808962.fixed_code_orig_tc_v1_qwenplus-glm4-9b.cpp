#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> uniqueBalls; // Using a set to store unique integers
    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int n, x;
        cin >> n; // Reading the type of query

        if(n == 1) {
            cin >> x; // Reading the value x for the "put" operation
            uniqueBalls.insert(x); // Insert x into the set
        } else if(n == 2) {
            cin >> x; // Reading the value x for the "remove" operation
            uniqueBalls.erase(x); // Remove x from the set
        } else {
            cout << uniqueBalls.size() << endl; // Output the number of unique balls in the bag
        }
    }
    
    return 0;
}