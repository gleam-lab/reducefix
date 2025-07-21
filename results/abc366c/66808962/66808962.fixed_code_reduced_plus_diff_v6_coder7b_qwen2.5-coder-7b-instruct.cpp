#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, int> countMap;
    set<int> uniqueValues;

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            if (countMap[x] == 0) {
                uniqueValues.insert(x);
            }
            countMap[x]++;
        } else if (type == 2) {
            int x;
            cin >> x;
            countMap[x]--;
            if (countMap[x] == 0) {
                uniqueValues.erase(uniqueValues.find(x));
            }
        } else {
            cout << uniqueValues.size() << endl;
        }
    }

    return 0;
}