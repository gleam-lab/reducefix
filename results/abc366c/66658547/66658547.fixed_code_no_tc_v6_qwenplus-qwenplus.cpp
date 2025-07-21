#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    
    map<int, int> freq;  // To keep count of each number's occurrences
    while (q--) {
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
            cout << freq.size() << "\n";
        }
    }

    return 0;
}