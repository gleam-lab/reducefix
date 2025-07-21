#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Q;
    cin >> Q;
    unordered_set<int> s;
    vector<int> results;

    while (Q--) {
        int query;
        cin >> query;
        if (query == 1) {
            int x;
            cin >> x;
            s.insert(x);
        } else if (query == 2) {
            int x;
            cin >> x;
            s.erase(x);
        } else {
            results.push_back(s.size());
        }
    }

    for (int result : results) {
        cout << result << "\n";
    }

    return 0;
}