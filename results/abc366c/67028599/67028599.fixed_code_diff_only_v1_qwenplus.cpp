#include<bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    map<int, int> count; // To keep track of the count of each number in the bag
    int type, x;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            count[x]++;
        } else if (type == 2) {
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                count.erase(x);
            }
        } else {
            cout << count.size() << endl;
        }
    }

    return 0;
}