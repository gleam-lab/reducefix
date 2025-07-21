#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    set<int> all_elements;
    set<int> distinct_elements;

    for(int i = 0; i < n; ++i) {
        int type, x; cin >> type >> x;

        if(type == 1) {
            // Insert the element into both sets
            all_elements.insert(x);
            distinct_elements.insert(x);
        } else if(type == 2) {
            // Erase the element from both sets
            auto it = all_elements.find(x);
            if(it != end(all_elements)) {
                all_elements.erase(it);
                distinct_elements.erase(distinct_elements.find(x));
            }
        } else if(type == 3) {
            // Output the size of the distinct elements set
            cout << distinct_elements.size() << '\n';
        }
    }

    return 0;
}