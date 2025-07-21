#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // Disable synchronization with C++ I/O.
    cin.tie(nullptr); // Untie cin and cout for asynchronous I/O.
    cout.tie(nullptr);
    
    int Q; // Number of queries.
    cin >> Q;
    
    set<int> numbers; // Set to store unique numbers.
    
    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;
        
        if (query == 1) {
            int number;
            cin >> number;
            numbers.insert(number); // Insert the number maintaining uniqueness.
        } else if (query == 2) {
            int number;
            cin >> number;
            // Remove the number. Since std::set doesn't allow erasure by value,
            // we need to find the iterator to the specific element.
            auto it = numbers.find(number);
            if (it != numbers.end()) {
                numbers.erase(it); // Erase the element from the set.
            }
        } else if (query == 3) {
            cout << numbers.size() << "\n"; // Output the number of unique elements.
        }
    }
    
    return 0;
}