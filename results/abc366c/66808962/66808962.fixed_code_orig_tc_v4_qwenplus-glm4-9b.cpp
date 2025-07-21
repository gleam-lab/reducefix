#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int q;
    cin >> q;
    unordered_map<int, int> count;
    int distinct_count = 0;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) { // Add ball with integer x
            int x;
            cin >> x;
            count[x]++;
            if (count[x] == 1) {
                distinct_count++;
            }
        } else if (type == 2) { // Remove ball with integer x
            int x;
            cin >> x;
            count[x]--;
            if (count[x] == 0) {
                distinct_count--;
            }
        } else if (type == 3) { // Output the number of distinct integers
            cout << distinct_count << endl;
        }
    }
    return 0;
}