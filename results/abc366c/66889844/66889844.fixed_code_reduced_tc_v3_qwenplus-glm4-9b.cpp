#include <iostream>
#include <set>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    set<int> a;
    
    for (int i = 0; i < Q; i++) {
        int query_type;
        cin >> query_type;
        
        if (query_type == 1) {
            int x;
            cin >> x;
            a.insert(x);
        } else if (query_type == 2) {
            int x;
            cin >> x;
            a.erase(x);
        } else if (query_type == 3) {
            cout << a.size() << endl;
        }
    }
    
    return 0;
}