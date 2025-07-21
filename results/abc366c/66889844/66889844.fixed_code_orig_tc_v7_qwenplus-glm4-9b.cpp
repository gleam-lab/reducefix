#include <iostream>
#include <set>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    set<int> bag;

    for (int i = 0; i < Q; ++i) {
        int query_type;
        cin >> query_type;

        if (query_type == 1) {
            int ball_number;
            cin >> ball_number;
            bag.insert(ball_number);
        } else if (query_type == 2) {
            int ball_number;
            cin >> ball_number;
            bag.erase(ball_number);
        } else if (query_type == 3) {
            cout << bag.size() << endl;
        }
    }

    return 0;
}