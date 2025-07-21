#include <iostream>
#include <set>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    set<int> balls;
    
    for (int i = 0; i < Q; ++i) {
        int query_type;
        cin >> query_type;
        if (query_type == 1) {
            int ball;
            cin >> ball;
            balls.insert(ball);
        } else if (query_type == 2) {
            int ball;
            cin >> ball;
            balls.erase(ball);
        } else if (query_type == 3) {
            cout << balls.size() << endl;
        }
    }
    
    return 0;
}