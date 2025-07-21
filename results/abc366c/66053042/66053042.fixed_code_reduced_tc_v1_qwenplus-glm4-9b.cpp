#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> m;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            m[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            m[x]--;
            // No need to decrement n since the query guarantees that x exists in the map
        } else if (type == 3) {
            cout << m.size() << endl; // The size of the map represents the number of different integers
        }
    }
}