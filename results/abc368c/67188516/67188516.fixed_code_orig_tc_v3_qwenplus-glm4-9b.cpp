int N;
cin >> N;
vector<long long> H(N);

long long total_attacks = 0;

// Process each enemy's health
for (int i = 0; i < N; ++i) {
    long long health = H[i];
    // Maximum number of attacks needed to defeat this enemy
    // We use (health - 1) / 3 + 1 to ensure the health reaches 0 or below
    long long attacks_needed = (health - 1) / 3 + 1;
    total_attacks += attacks_needed;
}

cout << total_attacks << endl;