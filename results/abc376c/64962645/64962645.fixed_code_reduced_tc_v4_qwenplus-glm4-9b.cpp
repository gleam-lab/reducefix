#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n - 1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    // First, sort the toy sizes in descending order to consider the largest toy first
    sort(a.begin(), a.end(), greater<int>());

    // Sort the box sizes in descending order to consider the largest box first
    sort(b.begin(), b.end(), greater<int>());

    // Check if each toy can fit in any of the available boxes
    bool isPossible = true;
    for (int i = 0; i < n; ++i) {
        bool toyFits = false;
        // Try to fit the current toy into one of the boxes
        for (int j = 0; j < n - 1; ++j) {
            if (a[i] <= b[j]) {
                toyFits = true;
                break;
            }
        }
        // If no box fits the current toy, it's impossible to store all toys
        if (!toyFits) {
            isPossible = false;
            break;
        }
    }

    // If it's not possible to store all toys in the given boxes, print -1
    if (!isPossible) {
        cout << -1 << endl;
        return 0;
    }

    // The smallest box size needed is the size of the smallest box that can fit the largest toy
    cout << a[0] << endl;
    return 0;
}