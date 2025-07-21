#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    set<int> balls;
    int count = 0;
    
    while (Q--) {
        int query_type;
        cin >> query_type;
        
        if (query_type == 1) {
            int ball;
            cin >> ball;
            balls.insert(ball);
            count++;
        } else if (query_type == 2) {
            int ball;
            cin >> ball;
            balls.erase(ball);
            count--;
        } else if (query_type == 3) {
            cout << count << endl;
        }
    }
    
    return 0;
}