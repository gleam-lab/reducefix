#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> toys(n);
    vector<int> boxes(n-1);

    for (int i = 0; i < n; ++i)
        cin >> toys[i];
    for (int i = 0; i < n-1; ++i)
        cin >> boxes[i];

    // Including the size of the last box as 0 for simplicity
    boxes.push_back(0);

    // Sort toys and boxes
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    // Binary search for the smallest box size
    int left = 1, right = *max_element(boxes.begin(), boxes.end()) + 1;
    while (left < right) {
        int mid = (left + right) / 2;
        bool possible = true;
        for (int toy : toys) {
            if (toy > mid) {
                possible = false;
                break;
            }
        }

        if (possible) {
            right = mid;  // mid is valid, try for a smaller size
        } else {
            left = mid + 1;  // mid is not valid, try for a larger size
        }
    }

    // If left equals right, it is the smallest valid box size
    if (left <= *max_element(boxes.begin(), boxes.end())) {
        cout << left << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}