# CAN통신01_CAN Tranceiver & CAN Controller



✔ Tranceiver -> Transmitter + Receiver

✔ 제어기 속 MCU 속 HW(CPU, 메모리 등)을 부르는 말 -> `peripheral`

    CAN통신과 연관된 peripheral은 **`CAN Controller`** 이다!

<img src="CAN통신01_CAN%20Tranceiver%20&%20CAN%20Controller_assets/2023-02-09-08-53-49-image.png" title="" alt="" data-align="center">

- CAN Node가 제어기, 그 안에 MCU 들어있고, MCU 안에 다양한 페리펄러 들어있는데 그 중에 CAN통신과 연관된 Can Controller 도 있다.

- MCU가 Can Controller에 신호 주면 이 컨트롤러가 신호에 맞는 여러가지 작업을 함

- CAN 통신에서 메세지는 상단 그림의 Complete CAN Frame 그림 처럼 주어짐
  
  

CAN Controller

- 신호도 만들어서 보내고 버스에는 신호 하나만 있어야해서 버스에 신호 있는지 없는지도 체크함

CAN Transeiver

- CAN 스펙에 맞게 3.75V, 2.5V, 1.5V 전압 출력하고 반대로 그 전압을 읽어서 0인지 1인지 판단하는 역할 함

- 따라서 CAN High, CAN Low는 캔 트랜시버에 연결됨



<img src="CAN통신01_CAN%20Tranceiver%20&%20CAN%20Controller_assets/2023-02-09-14-46-10-image.png" title="" alt="" data-align="center">

✔ CAN Controller 가 어떤 데이터를 보내야할 때 0 또는 1로 보내는데 그 0 또는 1을 CAN Transceiver에게 전달

➡ CAN Transceiver가 각각 0 일 때, 1일 때 약속한 전압을 출력(**CAN TX**)

➡ CAN Transceiver가 BUS 와 연결된 전선의 전압값 읽어서 0인지 1인지 판단한 후 판단한 숫자를 CAN Controller에게 전달 (**CAN RX**)



⭐ CAN 통신을 하려면 CAN Transceiver 사용은 선택이 아니라 필수! ⭐

➡ 내가 캔통신 관련 업무를 하면 그 제어기에는 반드시 CAN Transceiver가 달려있다.



✔ CAN Transceiver마다 sleep mode, normal mode, listen only mode 이런 state machine을 갖고 있는게 있다.

➡ 따라서 CAN 관련 SW를 만들때 우리 제어기에 달린 CAN Transceiver가 무엇인지 보고 CAN Transceiver가 어떤 동작을 하는지 Data Sheet를 보고 CAN Transceiver를 컨트롤 해야함!



---

#### 🔗 요약

- 각각의 제어기 안에는 일종의 작은 컴퓨터인 MCU가 있다.



- MCU 내부에는 각종 peripheral들이 있고, 그 중에 CAN통신과 관련된 역할을 하는 CAN Controller라는 peripheral이 있따.

- CAN Controller가 송신하는 데이터는 CAN TX 핀을 통해서 캔 트랜시버에게 전달된다.

- CAN Tranceiver는 캔 컨트롤러로부터 정보를 받아서 CAN High, CAN Low 핀으로 실제 '전압'을 출력하는 역할을 한다.



- 반대로 다른 제어기가 메세지를 전송하면 CAN High, CAN Low의 전압값을 읽어서 비트로 해석하여 캔 컨트롤러 에게 전달해준다. (CAN RX핀)



- 캔 컨트롤러: 메세지에 담기는 값과 관련 (Data Link Layer라고 함)

- 트랜시버: 실제로 전선에 출력되는 전압과 관련 (Physical Layer라고 함)
