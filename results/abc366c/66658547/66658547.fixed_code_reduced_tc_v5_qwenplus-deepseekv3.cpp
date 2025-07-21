#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unordered_map<int, int> freq;
    int unique_count = 0;
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            if (freq[x] == 0) {
                unique_count++;
            }
            freq[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0) {
                unique_count--;
            }
        } else if (type == 3) {
            cout << unique_count << "\n";
        }
    }
    return 0;
}