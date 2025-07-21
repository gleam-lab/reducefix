#include <bits/stdc++.h>  // Use only the headers you need
using namespace std;

int main() {
    int n, q;
    cin >> n;  // Read the number of queries

    set<int> a;  // Use a set to store unique integers

    for (int i = 0; i < n; i++) {
        int query_type, x;
        cin >> query_type >> x;  // Read the query type and the integer

        if (query_type == 1) {
            a.insert(x);  // Insert x into the set
        } else if (query_type == 2) {
            a.erase(x);  // Remove x from the set
        } else if (query_type == 3) {
            cout << a.size() << endl;  // Print the size of the set
        }
    }

    return 0;
}