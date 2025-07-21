int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> pieces(M);

    // Read the pieces
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        pieces[i] = {a, b};
    }

    // Compute capturing patterns
    set<int> unique_capture_patterns;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            if (i != j) {
                // Check if the two pieces can capture each other
                if (can_capture(pieces[i], pieces[j])) {
                    int pattern = compute_pattern(pieces[i], pieces[j]);
                    unique_capture_patterns.insert(pattern);
                }
            }
        }
    }

    // Calculate the number of free squares
    int free_squares = N * N - unique_capture_patterns.size();

    // Output the result
    cout << free_squares << endl;
    return 0;
}

// Helper function to check if two pieces can capture each other
bool can_capture(pair<int, int> a, pair<int, int> b) {
    // Implement logic to check if (a, b) can capture (i, j)
}

// Helper function to compute the capturing pattern
int compute_pattern(pair<int, int> a, pair<int, int> b) {
    // Implement logic to compute the capturing pattern based on a and b
}