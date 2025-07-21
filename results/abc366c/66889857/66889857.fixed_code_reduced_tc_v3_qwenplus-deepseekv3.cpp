#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
    int Q; cin >> Q;
    unordered_map<int, int> count;
    set<int> distinct;

    rep(i, Q) {
        int query; cin >> query;
        if (query == 1) {
            int x; cin >> x;
            count[x]++;
            if (count[x] == 1) {
                distinct.insert(x);
            }
        } else if (query == 2) {
            int x; cin >> x;
            count[x]--;
            if (count[x] == 0) {
                distinct.erase(x);
            }
        } else if (query == 3) {
            cout << distinct.size() << endl;
        }
    }
}