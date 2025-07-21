#include <iostream>
#include <unordered_set>

using namespace std;

// Fast IO
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fastIO();

    int Q;
    cin >> Q;
    unordered_set<int> s;

    while (Q--) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int x;
            cin >> x;
            s.insert(x);
        } else if (queryType == 2) {
            int x;
            cin >> x;
            s.erase(x);
        } else if (queryType == 3) {
            cout << s.size() << "\n";
        }
    }

    return 0;
}