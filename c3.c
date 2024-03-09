/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // 랜덤때문에 

int findRoom(int persons[5]); // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // 배정 결과를 출력한다.

int main(){
	char mnames[10][20]; // 남학생명단(최대 10명)
	int mroom[10];		// 남학생명단별 호실 배정 목록
	char wnames[10][20]; // 여학생명단(최대 10명)
	int wroom[10];		// 여학생명단별 호실 배정 목록
	int person[2][5]={0};   // 2개 층별 5개 호실의 배정 인원 수 
	int mcount=0, wcount=0; // 인원 합계 (남, 여)
	int menu;

	srand(time(0));
	printf("===========================================\n");
	printf("생활관 호실 배정 프로그램\n");
	printf("===========================================\n");
	while(1){
		printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
		scanf("%d", &menu);
		if(menu==0) break;
		else if(menu==1) {
			if(mcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", mnames[mcount]);
			int roomno = findRoom(person[0]);
			mroom[mcount] = 100+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
			mcount++;
		}
		else if(menu==2) {
			if(wcount>=10) {
				printf("정원 초과입니다. 등록불가!\n");
				continue;
			}
			printf("학생 이름은? > ");
			scanf("%s", wnames[wcount]);
			int roomno = findRoom(person[1]);
			wroom[wcount] = 200+roomno;
			printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
			wcount++;
		}
	}

	printf("===========================================\n");
	printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
	printf("===========================================\n");
	printReport(mnames, mroom, mcount, wnames, wroom, wcount);

	return 0;
}

int findRoom(int persons[5]){
	int room;
	int er[5] = {0, }; // 빈 방 목록 
    int ec = 0; // 빈 방 카운트

// 이 곳에 생각 정리와 코드 구현
// 호실이므로 층은 생각하지 않기 (남자? 여자?)
// 5개의 호실에서 빈 베드가 있는 방을 랜덤으로 찾아내야 한다 
// for문으로 돌려서 빈방을 찾고 빈방목록을 만들어 표시해야 한다. 
// 1. 빈 베드가 있는 방 찾기 
// 주의사항 2명있는 방은 안된다 (조건: 2명 있는 방은 제외시켜야 한다)

//빈방찾기
	for(int i = 0; i < 5; i++){
		// 주의사항 2명있는 방은 안된다 (조건: 2명 있는 방은 제외시켜야 한다)
		if(persons[i] < 2){
			er[ec] = i; // 빈 방 목록에 추가
            ec++;
			//방 랜덤으로 뽑을 때 호수인 변수를 넘기기
			room = rand()%6;
		}
	}

	    // 빈 방이 존재할 경우 랜덤으로 선택
    if(ec > 0){
        room = er[rand() % ec];
    }
    else{
        // 빈 방이 없는 경우 -1 반환
        room = -1;
    }
// - 그 곳에서 랜덤으로 뽑아내야 한다. > 리턴값을 호실로 
return room;

}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
// 이 곳에 생각 정리와 코드 구현
// 남학생 출력 (순서대로 )
// 여학생 출력
// 호실별로 학생 명단을 저장
// mr에 남자들 호수가 저장되어있으므로 Index에 저장
// 배열이므로 -1 
// mn배열에 해당되는 것을 복사하여 명단 작성
int i = 0;
int j = 0; 

//남학생
printf("남학생 명단 [%d호]\n", mc);
for(i = 0; i < mc; i++){
	printf("%d. %s [%d]\n", i+1, mn[i], mr[i]);
}
printf("/n");

//여학생 명단
printf("여학생 명단 [%d호]\n", wc);
for(i = 0; i < wc; i++){
	printf("%d. %s [%d]\n", i+1, wn[i], wr[i]);
}

//호실별 배정 명단
//이중 for문으로 출력시키기 
printf("/n");
printf("호실별 배정 명단\n");

     // 호실별 배정 명단 출력
    printf("호실별 배정 명단\n");
    char roomAssignments[5][30][20] = {0}; // 호실별로 배정된 학생 명단을 저장하는 배열

    // 남학생 명단을 호실별로 저장
    for (int i = 0; i < mc; i++) {
        int roomIndex = mr[i] % 100 - 1; // 호실 번호로 인덱스 계산
        sprintf(roomAssignments[roomIndex][i], "%s", mn[i]);
    }

    // 여학생 명단을 호실별로 저장
    for (int i = 0; i < wc; i++) {
        int roomIndex = wr[i] % 100 - 1; // 호실 번호로 인덱스 계산
        sprintf(roomAssignments[roomIndex][i + mc], "%s", wn[i]);
    }

    // 호실별로 저장된 학생 명단을 출력
    for (int i = 0; i < 5; i++) {
        printf("%d호실: ", i + 101);
        for (int j = 0; j < mc + wc; j++) {
            if (roomAssignments[i][j][0] != '\0') {
                printf("%s ", roomAssignments[i][j]);
            }
        }
        printf("\n");
    }
}