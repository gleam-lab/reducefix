#include <iostream>
#include <set>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    set<int> balls;
    int currentQuery;

    for (int i = 0; i < Q; ++i) {
        cin >> currentQuery;
        if (currentQuery == 1) {
            int number;
            cin >> number;
            balls.insert(number);
        } else if (currentQuery == 2) {
            int number;
            cin >> number;
            balls.erase(number);
        } else if (currentQuery == 3) {
            cout << balls.size() << endl;
        }
    }

    return 0;
}