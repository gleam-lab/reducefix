#include <iostream>
#include <set>

using namespace std;

// Constants
const int MAXN = 1e6 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int Q;
    cin >> Q;
    set<int> s;

    while (Q--) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            s.insert(x);
        } else if (a == 2) {
            int x;
            cin >> x;
            s.erase(s.find(x));
        } else {
            cout << s.size() << '\n';
        }
    }

    return 0;
}