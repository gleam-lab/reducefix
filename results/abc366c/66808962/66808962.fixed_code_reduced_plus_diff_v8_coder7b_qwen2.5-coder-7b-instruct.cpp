#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <math.h>
#include <queue>
#include <iomanip> // setprecisionを使うため
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    unordered_map<int, int> countMap;
    multiset<int> countSet;
    
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int n, x;
        cin >> n;

        if (n == 1) {
            cin >> x;
            auto it = countMap.find(x);
            if (it == countMap.end()) {
                countMap[x] = 1;
                countSet.insert(1);
            } else {
                int prevCount = it->second;
                int newCount = ++(it->second);
                countSet.erase(countSet.find(prevCount));
                countSet.insert(newCount);
            }
        } else if (n == 2) {
            cin >> x;
            auto it = countMap.find(x);
            if (it != countMap.end()) {
                int prevCount = it->second;
                int newCount = --(it->second);
                if (newCount == 0) {
                    countMap.erase(it);
                } else {
                    countSet.erase(countSet.find(prevCount));
                    countSet.insert(newCount);
                }
            }
        } else {
            cout << countSet.size() << endl;
        }
    }

    return 0;
}