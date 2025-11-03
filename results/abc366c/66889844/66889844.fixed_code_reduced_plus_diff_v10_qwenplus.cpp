#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int q;
    cin >> q;
    
    map<int, int> ballCount; // Count of each number in the bag
    
    rep(i, q) {
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
}