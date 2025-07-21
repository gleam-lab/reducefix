#include <iostream>
#include <set>

using namespace std;

void solve() {
    int q;
    cin >> q;
    
    set<int> st; // Use a set to store unique integers
    int unique_count = 0; // Variable to keep track of the number of unique integers
    
    for (int i = 0; i < q; i++) {
        int query_type;
        cin >> query_type;
        
        if (query_type == 1) { // Insertion query
            int x;
            cin >> x;
            st.insert(x); // Insert x into the set
            if (st.size() > unique_count) { // Check if the unique count has increased
                unique_count++;
            }
        } else if (query_type == 2) { // Deletion query
            int x;
            cin >> x;
            st.erase(x); // Remove x from the set
            if (st.size() < unique_count) { // Check if the unique count has decreased
                unique_count--;
            }
        } else if (query_type == 3) { // Count query
            cout << unique_count << endl; // Output the current count of unique integers
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}