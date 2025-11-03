#include<bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;

    map<int, int> ballCount;
    int type, x;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            ballCount[x]++;
        } else if (type == 2) {
            cin >> x;
            ballCount[x]--;
            if (ballCount[x] == 0) {
                ballCount.erase(x);
            }
        } else {
            cout << ballCount.size() << endl;
        }
    }

    return 0;
}