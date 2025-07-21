#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    unordered_map<int, int> count;
    int distinct = 0;
    int type, x;
    while(q--) {
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
            cout << distinct << '\n';
        }
    }

    return 0;
}