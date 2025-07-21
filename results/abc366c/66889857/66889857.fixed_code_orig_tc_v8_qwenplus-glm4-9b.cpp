#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n; // Read the number of queries
    
    set<int> numbers; // To store the distinct numbers
    for (int i = 0; i < n; ++i) {
        int query_type;
        cin >> query_type; // Read the type of query
        
        if (query_type == 1) {
            int number;
            cin >> number; // Read the number for the insert query
            numbers.insert(number); // Insert the number into the set
        } else if (query_type == 2) {
            int number;
            cin >> number; // Read the number for the remove query
            numbers.erase(number); // Remove the number from the set
        } else if (query_type == 3) {
            cout << numbers.size() << endl; // Output the size of the set
        }
    }
    
    return 0;
}