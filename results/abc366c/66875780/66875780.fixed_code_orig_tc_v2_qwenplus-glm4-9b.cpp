#include <iostream>
#include <set>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    set<int> s;
    int count;
    for (int i = 0; i < Q; ++i) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            s.insert(x);
        } else if (a == 2) {
            int x;
            cin >> x;
            s.erase(x);
        } else if (a == 3) {
            count = s.size();
            for (int j = 0; j < count; ++j) {
                cout << "";
            }
            cout << count << endl;
        }
    }
    return 0;
}