class Solution {
    
    public void markRow(int[][] matrix , int i) {
            for(int j = 0 ; j < matrix[0].length ; j++) {
                if(matrix[i][j] != 0)
                    matrix[i][j] = -1000;
            }   
        }
    
    public void markCol(int[][] matrix , int i) {
            for(int j = 0 ; j < matrix.length ; j++) {
                if(matrix[j][i] != 0)
                    matrix[j][i] = -1000;
            }   
        }
    
    public void setZeroes(int[][] matrix) {
        for(int i = 0 ; i < matrix.length ; i++) {
            for(int j = 0 ; j < matrix[0].length ; j++) {
                if(matrix[i][j] == 0) {
                    markRow(matrix , i);
                    markCol(matrix , j);
                }
            }
        }
        
        for(int i = 0 ; i < matrix.length ; i++) {
            for(int j = 0 ; j < matrix[0].length ; j++) {
                if(matrix[i][j] == -1000) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
}