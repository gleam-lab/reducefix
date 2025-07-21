#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    set<int> balls;
    
    for (int i = 0; i < n; ++i) {
        int queryType;
        cin >> queryType;
        
        if (queryType == 1) {
            int ball;
            cin >> ball;
            balls.insert(ball);
        } else if (queryType == 2) {
            int ball;
            cin >> ball;
            balls.erase(ball);
        } else if (queryType == 3) {
            cout << balls.size() << endl;
        }
    }
    
    return 0;
}