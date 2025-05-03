void prims() {
    cout << "\n*Using Prims*\n";
    vector<int> visited(n, -1);
    visited[0] = 1;
    int min_cost = 0;

    for (int k = 0; k < n - 1; k++) {
        int min = INT_MAX;
        int row = -1, col = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 1) {
                for (int j = 0; j < n; j++) {
                    if (visited[j] == -1 && mat[i][j] != -1 && mat[i][j] < min) {
                        min = mat[i][j];
                        row = i;
                        col = j;
                    }
                }
            }
        }

        if (min == INT_MAX) {
            cout << "Graph is not connected.\n";
            return;
        }

        visited[col] = 1;
        cout << vertices[row] << " -> " << vertices[col] << " (cost: " << min << ")\n";
        min_cost += min;
    }

    cout << "\nTotal cost of MST: " << min_cost << endl;
}
