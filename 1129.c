#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int reporting[1001][1001];
int reported[1001];
char  *chart;
char  *report_chart;

int compare_index(const char *charts, const char* id_list[], size_t id_list_len)
{
    for (int i=0; i<id_list_len; i++)
    {
        if (strcmp(charts, id_list[i])==0)  //문자열이 같다면, index추출
            return i;
    }
    return 0;
}

int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) 
{
    int* answer = (int*)calloc(id_list_len, sizeof(int)); //할당받아서 바아로 0넣어버리기~
    char copy[21]; //const라 복사할 배열 만들어줘버리기~ 
    int a, b; // 비교할 특정 index만들 변수 만들기.

    for (int i=0; i< report_len; i++)
    {
        strcpy(copy, report[i]); // 문자열 복사해서 쓰래서 복사해서 씀.!
        chart = strtok(copy, " "); // 문자열 기준으로 나누는 함수가 있을거같아서 검색해보니 strtok이 뜸.
        report_chart = strtok(NULL, " "); // NULL " " 하면 뒷 문자열이 추출됨! 
        a = compare_index(chart, id_list, id_list_len);
        b = compare_index(report_chart, id_list, id_list_len);

        if (reporting[a][b] == 0)
        {
            reporting[a][b] = 1;
            reported[b]++;
        }
    }
        for (int i=0; i<id_list_len; i++)
        {
            // if (reported[i]>=k)
            // {
                for(int j=0; j< id_list_len; j++)
                {
                    if (reporting[i][j] == 1 && reported[j] >= k)
                        answer[i]++;
                }
            // }
        }

        
    
    return answer;
}
