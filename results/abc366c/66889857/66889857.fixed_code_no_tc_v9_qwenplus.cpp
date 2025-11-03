#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int Q;
    cin >> Q;
    
    map<int, int> count;
    int distinct = 0;
    
    rep(i, Q) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            if (count[x] == 0) {
                distinct++;
            }
            count[x]++;
        }
        else if (type == 2) {
            int x;
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                distinct--;
            }
        }
        else if (type == 3) {
            cout << distinct << endl;
        }
    }
    
    return 0;
}