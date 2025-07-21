int n, q;
vector<int> a, b;
vector<vector<int>> distances;

function<int(int)> getSum = [&](int index) {
    int sum = 0;
    while (index > 0) {
        sum += distances[index][0];
        index -= index & -index;
    }
    return sum;
};