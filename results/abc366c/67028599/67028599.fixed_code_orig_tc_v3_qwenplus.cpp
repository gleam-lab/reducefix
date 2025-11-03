#include<bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    map<int, int> freq;
    int type, x;
    
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            freq[x]++;
        } else if (type == 2) {
            cin >> x;
            freq[x]--;
            if (freq[x] == 0) {
                freq.erase(x);
            }
        } else {
            cout << freq.size() << endl;
        }
    }

    return 0;
}