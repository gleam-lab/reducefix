#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> process_queries(int q, vector<pair<int, int>>& queries) {
    set<int> unique_balls;
    vector<int> results;

    for (auto& query : queries) {
        int type = query.first;
        
        if (type == 1) {  // Add ball
            int ball_number = query.second;
            unique_balls.insert(ball_number);
        } else if (type == 2) {  // Remove ball
            int ball_number = query.second;
            unique_balls.erase(ball_number);
        } else if (type == 3) {  // Count unique balls
            results.push_back(unique_balls.size());
        }
    }

    return results;
}

int main() {
    int q;
    cin >> q;

    vector<pair<int, int>> queries;
    for (int i = 0; i < q; ++i) {
        int type, x;
        cin >> type >> x;
        queries.emplace_back(type, x);
    }

    vector<int> results = process_queries(q, queries);

    for (int result : results) {
        cout << result << "\n";
    }

    return 0;
}