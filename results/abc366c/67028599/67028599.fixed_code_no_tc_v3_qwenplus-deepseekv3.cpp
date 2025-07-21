#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    unordered_map<int, int> freq;
    set<int> distinct;
    int type, x;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            freq[x]++;
            if (freq[x] == 1) {
                distinct.insert(x);
            }
        } else if (type == 2) {
            cin >> x;
            freq[x]--;
            if (freq[x] == 0) {
                distinct.erase(x);
            }
        } else {
            cout << distinct.size() << '\n';
        }
    }

    return 0;
}