#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    vector<int> queries;
    set<int> distinctNumbers;

    int query, x;
    while (cin >> query) {
        if (query == 1) {
            cin >> x;
            distinctNumbers.insert(x);
        } else if (query == 2) {
            cin >> x;
            distinctNumbers.erase(x);
        } else if (query == 3) {
            cout << distinctNumbers.size() << endl;
        }
    }

    return 0;
}