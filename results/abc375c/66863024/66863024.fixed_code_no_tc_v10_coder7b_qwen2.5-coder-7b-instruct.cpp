#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<long long, long long>> points(n);
    for(int i = 0; i < n; ++i){
        cin >> points[i].first >> points[i].second;
    }

    long long total_cost = 0;

    // Calculate the cost of moving from the origin to the first point
    total_cost += abs(points[0].first) + abs(points[0].second);

    // Calculate the cost of moving between consecutive points
    for(int i = 0; i < n-1; ++i){
        total_cost += abs(points[i+1].first - points[i].first) + abs(points[i+1].second - points[i].second);
    }

    // Calculate the cost of returning to the origin from the last point
    total_cost += abs(points[n-1].first) + abs(points[n-1].second);

    cout << total_cost << endl;

    return 0;
}