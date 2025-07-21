#include <iostream>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    set<int> s;

    for (int i = 0; i < Q; ++i) {
        int operation;
        cin >> operation;

        if (operation == 1) {
            int number;
            cin >> number;
            s.insert(number);
        } else if (operation == 2) {
            int number;
            cin >> number;
            s.erase(number);
        } else { // operation == 3
            cout << s.size() << '\n';
        }
    }

    return 0;
}