#include <iostream>
#include <map>

using namespace std;

int main() {
    int q;
    cin >> q;
    map<int, int> balls;
    int distinct_count = 0;

    for (int i = 0; i < q; ++i) {
        int query_type;
        cin >> query_type;
        if (query_type == 1) {
            int x;
            cin >> x;
            balls[x]++;  // Increment the count for integer x
            if (balls[x] == 1) {  // If this is the first occurrence of x
                distinct_count++;  // Increment the count of distinct integers
            }
        } else if (query_type == 2) {
            int x;
            cin >> x;
            balls[x]--;  // Decrement the count for integer x
            if (balls[x] == 0) {  // If there are no more x's in the bag
                distinct_count--;  // Decrement the count of distinct integers
            }
        } else {  // query_type == 3
            cout << distinct_count << endl;  // Output the count of distinct integers
        }
    }

    return 0;
}