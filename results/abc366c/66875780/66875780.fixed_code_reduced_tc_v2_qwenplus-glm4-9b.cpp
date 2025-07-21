#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int Q;
    cin >> Q;
    
    unordered_map<int, int> ball_count;
    while (Q--) {
        int a;
        cin >> a;
        if (a == 1) {
            int x;
            cin >> x;
            ball_count[x]++;
        } else if (a == 2) {
            int x;
            cin >> x;
            ball_count[x]--;
            if (ball_count[x] == 0) {
                ball_count.erase(x);
            }
        } else {
            cout << ball_count.size() << "\n";
        }
    }
    
    return 0;
}