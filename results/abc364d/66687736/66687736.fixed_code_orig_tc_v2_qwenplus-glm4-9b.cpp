for each B_j:
    distances = []
    for each A_i:
        distances.push_back(abs(A_i - B_j))
    sort(distances)
    print(distances[k_j - 1])