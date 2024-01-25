class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int colLength = matrix[0].size();
        int rowLength = matrix.size();
      
       for(int col = 0; col < colLength; col++){
           int counter = 0;
           for(int row = rowLength - 1; row > counter; row--){
               swap(matrix[row][col],matrix[counter][col]);
               counter++;
           }
       }

       int counter = -1;
       for(int col = 0 ; col < colLength; col++){
           int elemIndex = colLength - 1 ;
           counter++;
           for(int rowPointer = rowLength - 1; rowPointer > 0; rowPointer--){
               if(rowPointer == col) break;
               swap(matrix[rowPointer][col],matrix[counter][elemIndex]);
               elemIndex--;
           }
       }
        
    }
};