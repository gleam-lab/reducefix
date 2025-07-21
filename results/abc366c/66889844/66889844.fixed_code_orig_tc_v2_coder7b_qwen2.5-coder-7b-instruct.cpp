#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    multiset<int> bag;
    set<int> unique_elements;

    while (n--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            bag.insert(x);
            unique_elements.insert(x);
        } else if (type == 2) {
            int x;
            cin >> x;
            bag.erase(bag.find(x));
            unique_elements.erase(unique_elements.find(x));
        } else if (type == 3) {
            cout << unique_elements.size() << '\n';
        }
    }

    return 0;
}