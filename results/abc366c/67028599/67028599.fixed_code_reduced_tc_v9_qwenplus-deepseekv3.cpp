#include<bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    
    map<int, int> count;
    int unique_count = 0;
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            if (count[x] == 0) {
                unique_count++;
            }
            count[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            if (count[x] == 1) {
                unique_count--;
            }
            count[x]--;
            if (count[x] == 0) {
                count.erase(x);
            }
        } else if (type == 3) {
            cout << unique_count << endl;
        }
    }
    
    return 0;
}