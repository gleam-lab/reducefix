#include <iostream>
#include <set>
using namespace std;

int main() {
    int q;
    cin >> q;

    set<int> balls;
    int count = 0;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        
        if (type == 1) { // Add ball
            int x;
            cin >> x;
            balls.insert(x);
        } else if (type == 2) { // Remove ball
            int x;
            cin >> x;
            balls.erase(x);
        } else if (type == 3) { // Output the number of distinct balls
            cout << balls.size() << endl;
        }
    }

    return 0;
}