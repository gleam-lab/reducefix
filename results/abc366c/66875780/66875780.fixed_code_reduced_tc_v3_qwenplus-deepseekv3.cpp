#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Q;
    cin >> Q;
    unordered_map<int, int> count;
    unordered_set<int> distinct;

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            if (count[x] == 0) {
                distinct.insert(x);
            }
            count[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                distinct.erase(x);
            }
        } else if (type == 3) {
            cout << distinct.size() << "\n";
        }
    }

    return 0;
}