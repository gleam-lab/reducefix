#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    set<int> balls;
    vector<int> results;

    for (int i = 0; i < Q; i++) {
        int query_type;
        cin >> query_type;

        if (query_type == 1) {
            int number;
            cin >> number;
            balls.insert(number);
        } else if (query_type == 2) {
            int number;
            cin >> number;
            balls.erase(number);
        } else if (query_type == 3) {
            results.push_back(balls.size());
        }
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}