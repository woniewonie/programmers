#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0;
    int width=0;
    int height=0;
    int temp; 
  
    for(int i=0; i< sizes_rows; i++)
    {
        if (sizes[i][0] < sizes[i][1])
        {
            temp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = temp;
        }
    }
    for (int i=0; i<sizes_rows; i++)
    {
        if (width < sizes[i][0]) width = sizes[i][0];
        if (height < sizes[i][1]) height = sizes[i][1];
    }

    answer = width * height;
    return answer;
}
