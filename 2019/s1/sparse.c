#include <stdio.h>

int isSparse(int M[][4], int rows);

int main(void) {
    int A[5][4] = {{5,4,6,7},{1,2,3,4},{5,6,4,2},{4,5,3,2},{3,5,4,1}};
    int B[4][4] = {{0,1,2,3},{0,0,0,1},{1,0,0,0},{1,0,0,2}};

    if (isSparse(A,5)) {
        printf("A is sparse\n");
    }
    else {
        printf("A is dense\n");
    }
    
    if (isSparse(B,4)) {
        printf("B is sparse\n");
    }
    else {
        printf("B is dense\n");
    }
    
    return 0;
}

/* int isSparse(M, rows) determines whether matrices with 4 columns 
 * are sparse.
 * M: a nx4 matrix, rows: the number of rows in the matrix
 * returns: 1 if matrix is sparse, 0 if it is not sparse
 * limitations:  only works for matrices with 4 columns, would require 
 * a different function - or use of dynamic arrays, covered later, to 
 * generalise to any number of columns
*/

int isSparse(int M[][4], int rows) {
    
    int cols = 4; // only works for arrays with 4 columns
    int zeros = 0;
    
    for (int r=0; r < rows; r++) {
        for (int c=0; c < cols; c++) {
            if (M[r][c] == 0) {
                zeros++;
            }
        }
    }
    
    if (zeros > rows * cols / 2) {
        return 1;
    }
    
    return 0;
}
