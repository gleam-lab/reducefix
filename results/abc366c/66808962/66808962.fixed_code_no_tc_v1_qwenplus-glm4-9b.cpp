#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> ball_count;
    int q;
    cin >> q;

    while (q--) {
        int command;
        cin >> command;
        if (command == 1) {
            int x;
            cin >> x;
            ball_count[x]++;
        } else if (command == 2) {
            int x;
            cin >> x;
            ball_count[x]--;
            if (ball_count[x] == 0) {
                ball_count.erase(x);
            }
        } else if (command == 3) {
            cout << ball_count.size() << endl;
        }
    }
    return 0;
}