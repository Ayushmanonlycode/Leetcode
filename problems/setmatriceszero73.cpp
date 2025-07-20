class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        // Get dimensions of the matrix
        int n = matrix.size();
        if (n == 0) return; // Handle empty matrix
        int m = matrix[0].size();
        if (m == 0) return; // Handle empty rows

        int col0 = 1; // This flag indicates if the first column needs to be zeroed

        // Step 1: Traverse the matrix and use the first row and first column
        // as markers. Also, use 'col0' for the special case of the 0th column.
        for (int i = 0; i < n; i++) {
            // Check if the current element in the 0th column is 0.
            // This handles the case where an element like matrix[i][0] (i > 0) is 0.
            if (matrix[i][0] == 0) {
                col0 = 0; // Mark that the first column needs to be zeroed
            }

            // Iterate through the rest of the columns (from 1 to m-1)
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // If matrix[i][j] is 0, mark its corresponding
                    // first row element (matrix[i][0]) and
                    // first column element (matrix[0][j]) as 0.
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Mark with 0 from (1,1) to (n-1, m-1) based on the markers.
        // Iterate from the second last row/column backwards to avoid
        // using a modified marker for rows/columns that haven't been processed yet.
        // Example: if matrix[1][0] becomes 0 due to some matrix[1][j] == 0,
        // and then matrix[0][1] becomes 0 due to some matrix[i][1] == 0,
        // we want to ensure matrix[1][1] is correctly processed.
        // Iterating backwards is generally safer for in-place modifications that
        // depend on previously set flags in the same structure.
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 1; j--) { // Start from j=1
                // If the corresponding first row element or first column element is 0,
                // then set the current cell to 0.
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
            // After processing columns for current row 'i' (from m-1 down to 1),
            // now handle the matrix[i][0] based on the col0 flag.
            // This order is important: process main matrix first, then edge cases.
            if (col0 == 0) {
                matrix[i][0] = 0;
            }
        }
    }
};          