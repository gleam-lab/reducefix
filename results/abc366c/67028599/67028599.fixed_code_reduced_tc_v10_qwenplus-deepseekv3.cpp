#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    unordered_map<int, int> count;
    int distinct = 0;

    while(q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            if (count[x] == 0) {
                distinct++;
            }
            count[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            if (count[x] == 1) {
                distinct--;
            }
            count[x]--;
        } else {
            cout << distinct << '\n';
        }
    }

    return 0;
}