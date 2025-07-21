#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> st;
    while (q--) {
        int type, x;
        cin >> type;
        switch (type) {
            case 1:
                cin >> x;
                st.insert(x);
                break;
            case 2:
                cin >> x;
                st.erase(x);
                break;
            case 3:
                cout << st.size() << endl;
                break;
        }
    }
    return 0;
}