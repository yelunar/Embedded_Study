.text            
.global main

main:
    sub	sp, sp, #16   // 16바이트 단위 stack 할당
    mov w0, #0        // w0 레지스터에 0값 저장
    str w0, [sp, #12] // stack 공간(int i: 4바이트) 0값 저장

    ldr x1, =message // .data 섹션의 "RealLinux" 주소값 x1에 저장
    mov x0, sp       // main함수 스택 가장위 공간 주소값 x0에 저장

.loop1:
    ldr x2, [x1] // .data 섹션의 "RealLinux" 한칸씩 문자값 x2에 저장
    str x2, [x0] // main 함수 스택공간내 str[i] 한칸값 x1에 저장
    add x0, x0, 1 // 스택 주소 1바이트 증가
    add x1, x1, 1 // .data 섹션의 "RealLinux" 주소 1바이트 증가

    ldr	w3, [sp, 12] // int i 변수값을 w3에 저장
    add w3, w3, 1    // w3 값 +1 증가
    str w3, [sp, 12] // int i 변수값에 저장
    cmp	w3, 8        // w3 과 8 비교
    ble .loop1       // if w3 <=8 면 .loop1 으로 점프

    mov w0, #0
    str w0, [sp, #12] // stack 공간(int i: 4바이트) 0값 저장
    mov x1, sp        // x1에 main 함수 스택주소 저장

.loop2:
    add x1, sp, w0
    mov x0, #1        // write 함수 인자1: fd 값 1 (stdout)
    mov x2, #1        // write 함수 인자3: 출력길이
    mov x8, 0x40      // write 함수 syscall number 0x40 (64)
    svc 0             // syscall 명령

    ldr	w0, [sp, 12]
    add w0, w0, 1
    str w0, [sp, 12]
    cmp	w0, 8
    ble .loop2

    add	sp, sp, #16   // main 함수 stack 공간 해지
    ret               // main 함수 종료(return)

.data
message: .asciz "RealLinux"
len = . - message

