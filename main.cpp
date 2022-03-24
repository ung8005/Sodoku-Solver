class Solution {
public:
    int boxSize = 3; 
    int rowSize;
        
    int rows = [rowSize][rowSize + 1];
    int columns = [rowSize][rowSize + 1];
    int boxes = [rowSize][rowSize + 1];
        
    char board;
        
    bool solved = false; 
};
*******************************************************************************  
    // Inspect if a number can be placed in the cell
    public bool bCanPlace (int numToPlace, int row, int column) {
        int index; 
        index = (row/rowSize)*rowSize + column/rowSize;
        return rows[row][numToPlace] + columns[column][numToPlace] 
               + boxes[index][numToPlace] == 0;
    };
 
*******************************************************************************  
    // Place a number in the cell 
    public void placeNumber (int numToPlace, int row, int column) {
        int index;
        index = (row/rowSize)*rowSize + column/rowSize;
        rows[row][numToPlace]++;
        columns[column][numToPlace]++;
        boxes[index][numToPlace]++;
        board[row][column] = (char)(numToPlace + '0');
    };

*******************************************************************************  
    // If the number doesn't lead to a solution, remove it. 
      public void removeNumber (int numToPlace, int row, int column) {
        int index;
        index = (row/rowSize)*rowSize + column/rowSize;
        rows[row][numToPlace]--;
        columns[column][numToPlace]--;
        boxes[index][numToPlace]--;
        board[row][column] = '.';
      };
    
*******************************************************************************     
    // Backtrack 
    public void backtrack (int row, int column) {
    // if the cell is empty
    if (board[row][column] == '.') {
      // iterate over all numbers from 1 to 9
        for (int numToPlace = 1; numToPlace < 10; numToPlace++) {
            if (bCanPlace (numToPlace, row, column)) {
                placeNumber (numToPlace, row, column);
                placeNextNumbers (row, column);
            }
            // if sudoku is solved, don't backtrack
            if (!sudokuSolved) {
                removeNumber(d, row, column);
            }
        }
      }
        else placeNextNumbers (row, column);
    }; 
    
*******************************************************************************    
    // Recursively call the backtrack functiomn to continue to place 
    // numbers until the last sell is reached; the sodoku is solved. 
    public void placeNextNumbers (int row, int column) {
          // if we're in the last cell, that means we have the solution
          if ((column == rowSize - 1) && (row == rowSize - 1)) {
              solved = true;
          }
          // if we're not in the last cell, continue to find solution
          else {
              // if we're in the end of the row, go to the next row
              if (column == rowSize - 1) {
                  backtrack (row + 1, 0);
              }
              // go to the next column
              else backtrack (row, col + 1);
          }
    };

*******************************************************************************
    public void solveSudoku (char board[][]) {
        this.board = board;
        char num;
        // init rows, columns and boxes
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < rowSize; j++) {
                num = board[i][j];
                    if (num != '.') {
                        int numToPlace = Character.getNumericValue(num);
                        placeNumber (numToPlace, i, j);
                    }
            }
        }
    backtrack(0, 0);
   };