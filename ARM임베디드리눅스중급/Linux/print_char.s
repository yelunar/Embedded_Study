.text            
.global main

main:
    sub	sp, sp, #16   // 16바이트 단위 stack 할당
    mov w0, #97       // w0 레지스터에 0x61(97) 'a'값 저장
    str w0, [sp, #15] // stack 공간(char ch: 1바이트) 1값 저장
    add x1, sp, #15   // int ch 변수 메모리공간의 주소를
	              // w3 에 저장
	              // (write 함수 인자2)

    mov x0, #1        // write 함수 인자1: fd 값 1 (stdout)
    mov x2, #1        // write 함수 인자3: 출력길이
    mov x8, 0x40      // write 함수 syscall number 0x40 (64)
    svc 0             // syscall 명령

    add	sp, sp, #16   // main 함수 stack 공간 해지
    ret               // main 함수 종료(return)

