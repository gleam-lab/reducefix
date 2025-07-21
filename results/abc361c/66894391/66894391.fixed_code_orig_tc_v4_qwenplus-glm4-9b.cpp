#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    // Remove k elements from both ends
    a.erase(a.begin(), a.begin() + k);
    a.erase(a.end() - k, a.end());

    // Output the difference between the last and first element
    cout << a.back() - a.front() << '\n';

    return 0;
}