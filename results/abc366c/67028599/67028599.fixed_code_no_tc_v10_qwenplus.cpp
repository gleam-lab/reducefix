#include<bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    map<int, int> count; // Tracks the count of each integer in the bag
    int distinct = 0;    // Current number of distinct integers

    int type, x;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            if (count[x] == 0) {
                distinct++;
            }
            count[x]++;
        } else if (type == 2) {
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                distinct--;
            }
        } else {
            cout << distinct << endl;
        }
    }

    return 0;
}