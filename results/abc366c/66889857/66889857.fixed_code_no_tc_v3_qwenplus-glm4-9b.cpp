#include <iostream>
#include <set>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    set<int> a;

    for (int i = 0; i < Q; i++) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int x;
            cin >> x;
            a.insert(x);
        } else if (queryType == 2) {
            int x;
            cin >> x;
            a.erase(x);
        } else if (queryType == 3) {
            cout << a.size() << endl;
        }
    }

    return 0;
}