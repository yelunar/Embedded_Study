.text            
.global main

main:
    sub	sp, sp, #16   // 16바이트 단위 stack 할당
    mov w0, #1024     // w0 레지스터에 1024(0x400)값 저장
    str w0, [sp, #8] // stack 공간(int a: 4바이트) 1024값 저장
    ldr w1, [sp, #8] // int a 변수 메모리공간의 값을 w1 에 저장
    str w1, [sp, #12]  // stack 공간(int b: 4바이트) w1의 값 저장

    add	sp, sp, #16   // main 함수 stack 공간 해지
    ret               // main 함수 종료(return)

