#include <stdio.h>
#include <stdlib.h>

const int constval = 30; // 상수

int uninitial; // 초기화 안된 전역 변수
int initial = 30; // 초기화 된 전역 변수
static int staticvalue = 30; // 정적 변수

int func(){ // 함수
    return 30;
}

int main(int arg, const char *argv[]){

    int localvalue = 30; // 지역변수

    char *arr = malloc(sizeof(char)*10); // 동적 할당 변수

    return 0;
}

