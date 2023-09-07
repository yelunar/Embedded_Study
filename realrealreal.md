이게찐이다!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

1. ARM 개념과 기본구조
   -> ARM이 뭔지 약어, 뜻, 많이사용되는 제품군 (A` M~ R~ 차이)
   
   -> OS : Mac Window Android Linux RTOS
    F/W
   -> OS가 왜올라가야하냐? -> OS 기능

2. ARM process & Boot
- p350 기반 (여기는 마구마구 파도됨.... )
+ Bootloader (RAM)
+ Startup code (MCU code start)
  -> vector table (exception table)
  -> Core
+ source code
3. Build system (ㅜㅜ)
+ Memory map

.c .h .s .o

---

## ARM

- ARM 아키텍처
  
  - ARM 아키텍처는 ARM프로세서를 설계하는 디자인을 의미하며 프로그래머 모델을 의미 ➡️ 명령어, 레지스터 구조, 메모리 구조 등의 프로세스 기본구조와 동작원리에 대한 정의
    
    ![](https://blog.kakaocdn.net/dn/b6D08t/btqMehBwLhi/dYcki0UK8403TtPcBoARvk/img.png)
  
  - RISC(Reduced Instruction Set Computer) 아키텍처로 분류되며, 간결한 명령어 세트를 가지고 있어 명령어 실행이 빠름
  
  - ARM 아키텍처는 32비트와 64비트 버전으로 나눠지며, 32비트 아키텍처는 ARMv7-A, ARMv7-R, ARMv7-M과 같이 다양한 프로파일이 있습니다. 64비트 아키텍처는 ARMv8-A로 알려져 있음

- ARM 프로세서
  
  - ARM 아키텍처를 기반으로 설계된 하드웨어를 가진 중앙 처리 장치(CPU)를 의미
    
    -  메모리, 인터페이스, 라디오, 시스템 온 칩, 시스템 온 모듈 등이 포함
  
  - ARM 프로세서는 저전력, 고성능, 중형 및 대형 서버 시스템용으로 다양한 프로파일 및 모델로 개발되어 사용 
  
  - RISC 아키텍처가 있는 프로세서는 일반적으로 복잡한 명령 세트 컴퓨팅 (CISC) 아키텍처보다 적은 트랜지스터를 필요로 하여 비용, 전력소비 및 열 방출을 향상시킴

- ARM Core
  
  - ARM아키텍처의 주요기능을 활용해 구현된 ARM프로세서의 핵심부분을 ARM core
  
  - 전체 모바일 기기의 95%에 ARM 코어가 들어감 > AP설계

---















---

## Build System

#### **컴파일 과정**

![](https://blog.kakaocdn.net/dn/Gb9WO/btrdpL4fvcQ/spc9IYinoZhgHRmJ0l0kjK/img.png)

컴파일 과정은 4가지 단계 `전처리 과정 - 컴파일 과정 - 어셈블리 과정 - 링킹 과정)`로 나누어 진다.

이 4가지 단계를 묶어서 컴파일 과정, 빌드 과정이라고 부르기도 하고 컴파일 과정과 링킹 과정을 따로 나눠서 부르기도 한다.

보통 빌드 과정은 컴파일 과정보다 넓은 의미(빌드=컴파일+링킹)로 사용되는데 상황에 맞게 이해하면 될 거 같다.



##### **1.** **전처리(Pre-processing) 과정**

<img src="https://blog.kakaocdn.net/dn/xVMXr/btrdqKw3ccJ/ARAfM8BBcKlMQyN3rIQ691/img.png" title="" alt="" width="331">

**전처리(Pre-processing) 과정**은 전처리기(Preprocessor)를 통해 소스 코드 파일(*.c)을 전처리된 소스 코드 파일(*.i)로 변환하는 과정이다.

이 과정에서 대표적으로 **세 가지 작업**을 수행한다.

- **주석 제거** : 소스 코드에서 **주석을 전부 제거**한다. 주석은 사람들이 알아볼 수 있게 남긴 내용이지 컴퓨터가 알 필요는 없기 때문이다.

- **헤더 파일 삽입** : #include 지시문을 만나면 해당하는 헤더 파일을 찾아 **헤더 파일에 있는 모든 내용을 복사해서 소스 코드에 삽입**한다. 즉, 헤더 파일은 컴파일에 사용되지 않고 소스 코드 파일 내에 전부 복사된다. 헤더 파일에 선언된 함수 원형은 후에 링킹 과정을 통해 실제로 함수가 정의되어 있는 오브젝트 파일(컴파일된 소스 코드 파일)과 결합한다.

- **매크로 치환 및 적용** : #define 지시문에 정의된 매크로를 저장하고 같은 문자열을 만나면 **#define 된 내용으로 치환**한다. 간단하게 말해 매크로 이름을 찾아서 정의한 값으로 전부 바꿔준다.

##### **2.** **컴파일(Compilation) 과정**

<img src="https://blog.kakaocdn.net/dn/bLTLoJ/btrdpsDQiXD/dPcd4AFAaTpTLp4S5ODj5K/img.png" title="" alt="" width="400">

**컴파일(Compilation) 과정**은 컴파일러(Compiler)를 통해 전처리된 소스 코드 파일(*.i)을 어셈블리어 파일(*.s)로 변환하는 과정이다.

이 과정에서 우리가 일반적으로 컴파일하면 생각하는 **언어의 문법 검사**가 이루어진다. 또한 **Static한 영역(Data, BSS 영역)들의 메모리 할당**을 수행한다.

##### **3.** **어셈블리(Assembly) 과정**

<img src="https://blog.kakaocdn.net/dn/sz3Fu/btrdqSBMnid/qb4T0MZXpliiZ2xfFtuLM0/img.png" title="" alt="" width="395">

**어셈블리(Assembly) 과정**은 어셈블러(Assembler)를 통해 어셈블리어 파일(*.s)을 오브젝트 파일(*.o)로 변환하는 과정이다.

💡 **오브젝트 파일(Object File) 정의**

어셈블리 코드는 이제 더 이상 사람이 알아볼 수 없는 기계어로 변환되는데 이를 오브젝트 코드라 부른다.

오브젝트 코드로 구성된 파일을 `오브젝트 파일(Object File)`이라 부르며 이 오브젝트 파일은 특정한 파일 포맷을 가진다.

※ 오브젝트 파일 포맷의 종류는 **Windows**의 경우 **PE(Portable Executable),** **Linux**의 경우 `ELF(Executable and Linking Format)`로 나눠진다.

💡 **오브젝트 파일 포맷(Object File Format)**

오브젝트 파일 포맷은 다음과 같은 구조를 하고 있다.

<img src="https://blog.kakaocdn.net/dn/tMFGd/btrdon37ct9/Rng1Ns2LqARYZmKe0tTpG0/img.png" title="" alt="" width="223">

- **오브젝트 파일 헤더(Object File Header)** : 오브젝트 파일의 기초 정보를 가지고 있는 헤더

- **텍스트 섹션 (Text Section)** : 기계어로 변환된 코드가 들어 있는 부분

- **데이터 섹션(Data Section)**: 데이터(전역 변수, 정적 변수)가 들어 있는 부분

- **심볼 테이블 섹션(Symbol Table Section)** : 소스 코드에서 참조되는 심볼들의 이름과 주소가 정의 되어 있는 부분.

- **재배치 정보 섹션(Relocation Information Section)** : 링킹 전까지 심볼의 위치를 확정할 수 없으므로 심볼의 위치가 확정 나면 바꿔야 할 내용을 적어놓은 부분

- **디버깅 정보 섹션(Debugging Information Secion)** : 디버깅에 필요한 정보가 있는 부분



여기서 중요한 부분은 **심볼 테이블 섹션**과 **재배치 정보 섹션**이다.

심볼(Symbol)은 **함수나 변수를 식별할 때 사용하는 이름**으로 **심볼 테이블(Symbol Table)** 안에는 오브젝트 파일에서 참조되고 있는 심볼 정보(이름과 데이터의 주소 등) 가지고 있다.

이때 오브젝트 파일의 심볼 테이블에는 해당 오브젝트 파일의 심볼 정보만 가지고 있어야 하기 때문에 **다른 파일에서 참조되고 있는 심볼 정보의 경우 심볼 테이블에 저장할 수 없다**.

**#include<stdio.h> 라이브러리를 이용해서 printf 함수를 사용하는 소스 코드 파일이 있다고 가정해보자.**

<img src="https://blog.kakaocdn.net/dn/evQuzf/btrdmB2FsRq/6dqgfHPjFHOXaOjK1JINxK/img.png" title="" alt="" width="600">

우린 이 소스 코드 파일을 컴파일하여 오브젝트 파일을 생성할 수 있다.

하지만 이 오브젝트 파일은 **독립적으로 실행할 수 없다**. 이 파일 안에는 **printf 함수를 구현한 내용이 없기 때문**이다.

전처리 과정을 통해 #include<stdio.h>로부터 printf 함수의 원형은 복사했지만 **printf를 구현한 내용은 포함되어 있지 않다**. 오브젝트 파일 구조에서 말한 것처럼 심볼 테이블에는 해당 오브젝트 파일의 심볼 정보만 가지고 있지 **외부에서 참조하는 printf 함수에 대한 심볼 정보는 가지고 있지 않다**.

즉, 이 오브젝트 파일을 실행하기 위해서는 **printf 함수를 사용하는 오브젝트 파일**과 printf 함수를 구현한 오브젝트 파일(libc.a 라이브러리)을 **연결시키는 작업**이 필요하다.

이러한 연결 과정을 `링킹(Linking)`이라 부른다. 



##### **4. 링킹(Linking) 과정**

<img src="https://blog.kakaocdn.net/dn/dW1GTK/btrdqLirXQS/upv8Q3omleeiAIGGPlCJdk/img.png" title="" alt="" width="383">

**링킹(Linking) 과정**은 링커(Linker)를 통해 오브젝트 파일(*.o)들을 묶어 실행 파일로 만드는 과정이다.

이 과정에서 **오브젝트 파일들**과 프로그램에서 사용하는 **라이브러리 파일들**을 **링크**하여 **하나의 실행 파일**을 만든다.



💡 **링커의 역할**

링커의 역할은 크게 **심볼 해석**과 **재배치**로 나눌 수 있다.

<img src="https://blog.kakaocdn.net/dn/bt3Zgi/btrdly6bqc4/dr1x43NX2Qv0QonOYS7Idk/img.png" title="" alt="" width="431">

- **심볼 해석(Symbol Resolution)**
  
  **심볼 해석**은 각 오브젝트 파일에 있는 **심볼 참조를 어떤 심볼 정의에 연관시킬지 결정하는 과정**이다. 여러 개의 오브젝트 파일에 같은 이름의 함수 또는 변수가 정의되어 있을 때 어떤 파일의 어떤 함수를 사용할지 결정한다.

- **재배치(Relocation)**
  
  **재배치**는 오브젝트 파일에 있는 **데이터의 주소나 코드의 메모리 참조 주소를 알맞게 배치하는 과정**이다.
  
  링커가 컴파일러가 생성한 오브젝트 파일을 모아서 하나의 실행 파일을 만들 때, **각 오브젝트 파일에 있는 데이터의 주소나 코드의 메모리 참조 주소**가 **링커에 의해 합쳐진 실행 파일에서의 주소와 다르게 때문에 그것을 알맞게 수정**해줘야 한다.
  
  이를 위해 오브젝트 파일 안에 재배치 정보 섹션(Relocation Information Section)이 존재한다.
  
  링킹 과정에서 **같은 세션끼리 합쳐진 후 재배치**가 일어난다.

<img src="https://blog.kakaocdn.net/dn/bwt02u/btrdr4BPvps/lNZWkcxCnSWihTgfTJuOv1/img.png" title="" alt="" width="472">

위 그림을 통해 알 수 있듯이 오브젝트 파일 형식은 링킹 과정에서 링커가 여러 개의 오브젝트 파일들을 하나의 실행 파일로 묶을 때 필요한 정보를 효율적으로 파악할 수 있는 구조이다.

링킹을 하기 전 오브젝트 파일을 `배치 가능한 오브젝트 파일(Relocatable Object File)`이라 부르고 링킹을 통해 만들어지는 오브젝트 파일을 `실행 가능한 오브젝트 파일(Executable Object File)`이라 부른다.



※ 컴파일 과정 동안 연쇄적으로 사용하는 개발 도구들(전처리기-컴파일러-어셈블리-링커)을 묶어서 `툴체인(Toolchain)`이라고도 부른다.


