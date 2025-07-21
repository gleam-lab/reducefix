#include <iostream>
#include <set>
using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> st;
    
    for (int i = 0; i < q; ++i) {
        int type, x;
        cin >> type;
        switch (type) {
            case 1: // Insertion
                cin >> x;
                st.insert(x);
                break;
            case 2: // Deletion
                cin >> x;
                st.erase(x);
                break;
            case 3: // Count unique elements
                cout << st.size() << endl;
                break;
        }
    }
    
    return 0;
}