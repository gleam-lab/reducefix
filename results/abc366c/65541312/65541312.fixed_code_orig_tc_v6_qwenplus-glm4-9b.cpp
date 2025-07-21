#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int q;
    cin >> q;
    vector<set<int>> bags(1); // Using one bag initially
    int currentBagIndex = 0;
    int currentBagSize = 0;

    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int x;
            cin >> x;
            bags[currentBagIndex].insert(x);
            currentBagSize++;
        } else if (op == 2) {
            int x;
            cin >> x;
            bags[currentBagIndex].erase(x);
            currentBagSize--;
        } else if (op == 3) {
            cout << currentBagSize << endl;
        }
    }

    return 0;
}