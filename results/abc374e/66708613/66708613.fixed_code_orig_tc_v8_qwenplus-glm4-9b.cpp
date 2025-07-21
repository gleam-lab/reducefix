#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N;
    long X;
    cin >> N >> X;
    vector<pair<pair<long, long>, pair<long, long>>> A(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i].first.first >> A[i].first.second 
           >> A[i].second.first >> A[i].second.second;
    }

    sort(A.begin(), A.end());

    vector<long> cost(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cost[i] = cost[i - 1] + A[i - 1].second.first * i + A[i - 1].first.second * i * i;
    }

    long minCost = LLONG_MAX;
    for (int i = 1; i <= N; i++) {
        long maxCapacity = A[i - 1].second.second * i;
        long minCapacity = A[i - 1].first.first * i;
        if (minCapacity <= X && maxCapacity >= X) {
            long costToAchieveMin = cost[i] - X;
            long costToAchieveMax = cost[i] - X + maxCapacity * A[i - 1].second.first;
            minCost = min(minCost, costToAchieveMin + costToAchieveMax);
        }
    }

    if (minCost == LLONG_MAX) {
        cout << 0 << endl;
    } else {
        cout << minCost << endl;
    }

    return 0;
}