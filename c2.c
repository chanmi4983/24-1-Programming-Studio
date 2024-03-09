#include <stdio.h>

int main( ){
    int person[4][3]; // 4 3 개 층별 개 호실의 점호 인원 수
    int sum[3] = {0, }; // ( , , ) 점호 인원 수 합계 남 여 전체
    float ratio[3]; // ( , , ) 점호 인원 수 비율 남 여 전체
    int i, j; // 반복문을 위한 변수 

    //sum[0]: 점호 전체 인원수 
    //sum[1]: 점호 남자 인원수
    // 점호 여자 

    printf(" Check room (Men)\n");

    //i는 층 j는 호수
    
    for(i = 0; i < 2; i ++){
        for(j = 0; j < 3; j ++){
        printf("Room #%d0%d > ", i + 1, j + 1);
        scanf("%d", &person[i][j]);
        sum[0] += person[i][j];
        sum[1] += person[i][j];
        }
    }


    //줄 16 
    printf(" Check room (Women)\n");
        for(i = 2; i < 4; i ++){
            for(j = 0; j < 3; j ++){
            printf("Room #%d0%d > ", i + 1, j + 1);
            scanf("%d", &person[i][j]);
            sum[0] += person[i][j];
            sum[2] += person[i][j];
            }
    }

    ratio[0] = (float)sum[1]/24 * 100;
    ratio[1] = (float)sum[2]/24 * 100;
    ratio[2] = (float)sum[0]/48 * 100;

    printf(" Check Result \n");
    printf("Men: %d/24 (%.1f%%)\n", sum[1], ratio[1]);
    printf("Women: %d/24 (%.1f%%)\n", sum[2],ratio[2]);
    printf("Total: %d/48 (%.1f%%)\n", sum[2], ratio[0]);



    
    return 0;
}