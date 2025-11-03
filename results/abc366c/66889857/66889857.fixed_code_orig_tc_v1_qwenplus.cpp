#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int Q;
    cin >> Q;

    map<int, int> freq;
    
    rep(i, Q) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            freq[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0) {
                freq.erase(x);
            }
        } else if (type == 3) {
            cout << freq.size() << '\n';
        }
    }
}