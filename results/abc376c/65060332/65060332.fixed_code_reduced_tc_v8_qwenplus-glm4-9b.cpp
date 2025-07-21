#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 200100;
int n;
int a[MAX_N], b[MAX_N];
vector<int> toys, boxes;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        toys.push_back(a[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
        boxes.push_back(b[i]);
    }

    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    int min_box_size = INT_MAX;
    for (int size : boxes) {
        if (size < min_box_size) {
            min_box_size = size;
            break;
        }
    }

    bool possible = true;
    for (int i = 0; i < n && possible; i++) {
        if (toys[i] > min_box_size) {
            possible = false;
        } else if (i > 0 && toys[i] >= toys[i - 1]) {
            min_box_size = toys[i];
        }
    }

    if (possible) {
        cout << min_box_size;
    } else {
        cout << -1;
    }

    return 0;
}