#include <stdio.h>

int main( ){
    int size; // 크기
    int stars, blank1, blank2; // , 1 , 2 별의 갯수 빈칸 의 갯수 빈칸 의 갯수
    int i, j; // 반복문을 위한 변수 

    //시작 
    // 1단계
    // 2단계 
    // 3단계: size만큼 변화

    printf("size > ");
    scanf("%d", &size); //크기 입력받기 

    blank1 = 0;
    blank2 = size * 2 - 2;

    for(i = 0; i < size; i++){ //사이즈 만큼 반복
    for(j = 0; j < blank1; j++) printf(" ");
        printf("*");
        for(j = 0; j < blank2; j++)  printf(" ");
        printf("*");
        printf("\n");
        blank1++;
        blank2-=2;
    }

    stars = size * 2;
     for(i = 0; i < size; i++){ 
        for(j = 0; j < stars; j++)  printf("*");
        printf("\n");
     }

     blank1 = 0; 
     stars = size*2;
    for(i = 0; i < size; i++){ 
        for(j = 0; j < blank1; j++) 
        printf(" ");
         for(j = 0; j < stars; j++) 
         printf("*");
         printf("\n");
         blank1++; stars -=2;
     }

        
     stars = size*2;
    for(i = 0; i < stars; i++)
        printf("*");
        printf("\n");
   
    return 0;
}