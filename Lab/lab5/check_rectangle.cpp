#include "lab5_functions.h" // Include the declearation of the function

// You need to make sure the detected corner_points not form a line or point
bool check_rectangle(const int arr[][MAX_DIMENSION], int row, int col, int corner_points[]) {
    /***************Start your code here***************/
    int counting_row;
    int counting_column;
    if(corner_points[0] == corner_points[2] || corner_points[1] == corner_points[3])return 0;
    for(counting_row = corner_points[0];counting_row <= corner_points[2];counting_row++){
        for(counting_column = corner_points[1];counting_column <= corner_points[3];counting_column++)if (arr[counting_row][counting_column] == 0)return 0;
    }
    return 1;
    /***************End your code here***************/
}