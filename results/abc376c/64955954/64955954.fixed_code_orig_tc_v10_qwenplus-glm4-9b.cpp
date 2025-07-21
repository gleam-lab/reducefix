#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> toy_sizes(n), box_sizes(n-1);

    for (int i = 0; i < n; ++i) {
        cin >> toy_sizes[i];
    }
    sort(toy_sizes.begin(), toy_sizes.end(), greater<int>());

    for (int i = 0; i < n-1; ++i) {
        cin >> box_sizes[i];
    }
    sort(box_sizes.begin(), box_sizes.end());

    bool possible = true;
    int min_x = -1;

    for (int i = 0; i < n - 1; ++i) {
        if (toy_sizes[i] > box_sizes[i]) {
            possible = false;
            break;
        }
    }

    if (!possible || toy_sizes[n-1] > box_sizes[n-2]) {
        cout << -1 << endl;
    } else {
        min_x = box_sizes[n-2] + 1;
        cout << min_x << endl;
    }

    return 0;
}