#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    vector<int> queries(3 * Q); // There will be 3 * Q elements since each query can have 3 parts
    for (int i = 0; i < 3 * Q; ++i) {
        cin >> queries[i];
    }
    
    set<int> a;
    int query_index = 0;
    
    for (int i = 0; i < Q; ++i) {
        if (queries[query_index] == 1) { // Insert operation
            a.insert(queries[query_index + 1]);
            query_index += 2;
        } else if (queries[query_index] == 2) { // Remove operation
            a.erase(queries[query_index + 1]);
            query_index += 2;
        } else if (queries[query_index] == 3) { // Query size operation
            cout << a.size() << endl;
            query_index += 1;
        }
    }
    
    return 0;
}