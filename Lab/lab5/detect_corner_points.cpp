#include "lab5_functions.h" // Include the declearation of the function


// detect corner points of the possible rectangle
// corner points are inclusive to the possible rectangle
// corner_points[0]: row index of the top left corner
// corner_points[1]: column index of the top left corner
// corner_points[2]: row index of the bottom right corner
// corner_points[3]: column index of the bottom right corner
void detect_corner(const int arr[][MAX_DIMENSION], int row, int col, int corner_points[]) {
    /***************Start your code here***************/
    int counting_row;
    int counting_column;
    for(counting_row = 0;counting_row < row;counting_row++){
        for(counting_column = 0;counting_column < col;counting_column++)if (arr[counting_row][counting_column] == 1)break;
        if (arr[counting_row][counting_column] == 1)break;
    }
    corner_points[0] = counting_row;
    corner_points[1] = counting_column;
    for(counting_row = row - 1;counting_row >= corner_points[0];counting_row--){
        for(counting_column = col - 1;counting_column >= corner_points[1];counting_column--)if (arr[counting_row][counting_column] == 1)break;
        if (arr[counting_row][counting_column] == 1)break;
    }
    corner_points[2] = counting_row;
    corner_points[3] = counting_column;
    /***************End your code here***************/
}