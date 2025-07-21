#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> m;
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int type, x;
        cin >> type >> x;

        if (type == 1) {
            m[x]++;
        } else if (type == 2) {
            if (m[x] == 1) {
                m.erase(x);
            } else {
                m[x]--;
            }
        } else if (type == 3) {
            cout << m.size() << endl;
        }
    }

    return 0;
}