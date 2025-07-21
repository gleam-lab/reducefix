#include <iostream>
#include <set>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    set<int> balls;
    for (int i = 0; i < Q; ++i) {
        int query;
        cin >> query;
        if (query == 1) {
            int ball;
            cin >> ball;
            balls.insert(ball);
        } else if (query == 2) {
            int ball;
            cin >> ball;
            balls.erase(ball);
        } else if (query == 3) {
            cout << balls.size() << endl;
        }
    }
    return 0;
}