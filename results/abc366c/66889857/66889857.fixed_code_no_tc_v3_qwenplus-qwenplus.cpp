#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    multiset<int> bag; // Using multiset to allow multiple balls with the same number
    map<int, int> count; // To keep track of counts for efficient distinct element tracking

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            bag.insert(x);
            count[x]++;
        } 
        else if (type == 2) {
            int x;
            cin >> x;
            auto it = bag.find(x);
            if (it != bag.end()) {
                bag.erase(it);
                count[x]--;
                if (count[x] == 0) {
                    count.erase(x);
                }
            }
        } 
        else if (type == 3) {
            cout << count.size() << '\n';
        }
    }

    return 0;
}