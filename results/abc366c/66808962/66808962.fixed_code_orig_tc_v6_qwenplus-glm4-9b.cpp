#include <iostream>
#include <set>
using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> s;

    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;

        if (n == 1) {
            int x;
            cin >> x;
            s.insert(x);
        } else if (n == 2) {
            int x;
            cin >> x;
            s.erase(x);
        } else {
            cout << s.size() << endl;
        }
    }

    return 0;
}