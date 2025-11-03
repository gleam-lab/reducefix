#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int Q;
    cin >> Q;
    
    map<int, int> ballCount; // Count of each integer in the bag
    
    rep(i, Q) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            ballCount[x]++;
        }
        else if (type == 2) {
            int x;
            cin >> x;
            ballCount[x]--;
            if (ballCount[x] == 0) {
                ballCount.erase(x);
            }
        }
        else if (type == 3) {
            cout << ballCount.size() << endl;
        }
    }
    
    return 0;
}