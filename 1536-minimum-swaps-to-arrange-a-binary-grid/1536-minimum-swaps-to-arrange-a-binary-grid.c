int minSwaps(int** grid, int gridSize, int* gridColSize) {
    int n = gridSize;
    int* rightmost = (int*)malloc(n * sizeof(int));
    
    // Step 1: Find rightmost 1 for each row
    for (int i = 0; i < n; i++) {
        rightmost[i] = -1;  // Default: no 1s in the row
        for (int j = n - 1; j >= 0; j--) {
            if (grid[i][j] == 1) {
                rightmost[i] = j;
                break;
            }
        }
    }
    
    int swaps = 0;
    
    // Step 2: Arrange rows
    for (int i = 0; i < n; i++) {
        // Find a row that can be placed at position i
        // It needs rightmost <= i
        int pos = -1;
        for (int j = i; j < n; j++) {
            if (rightmost[j] <= i) {
                pos = j;
                break;
            }
        }
        
        // If no suitable row found, impossible
        if (pos == -1) {
            free(rightmost);
            return -1;
        }
        
        // Step 3: Bring this row to position i by adjacent swaps
        for (int j = pos; j > i; j--) {
            // Swap rows j and j-1
            int temp = rightmost[j];
            rightmost[j] = rightmost[j - 1];
            rightmost[j - 1] = temp;
            swaps++;
        }
    }
    
    free(rightmost);
    return swaps;
}