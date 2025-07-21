#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    multiset<int> balls;
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            balls.insert(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            auto it = balls.find(x);
            if (it != balls.end()) {
                balls.erase(it);
            }
        } else if (type == 3) {
            set<int> unique_balls(balls.begin(), balls.end());
            cout << unique_balls.size() << endl;
        }
    }

    return 0;
}