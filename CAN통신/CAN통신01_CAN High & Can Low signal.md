# CAN통신01_CAN High & Can Low signal



✔ 통신에서 메시지를 보낸다 ➡ 전선에 전기적 신호를 발생시켜 전달한다

 

<img src="CAN통신01_CAN%20High%20&%20Can%20Low%20signal_assets/2023-02-08-17-05-41-image.png" title="" alt="" data-align="center">

- CAN에서는 `CAN High, CAN Low 간의 전압 차를 이용`하여 데이터 표현
  
  - CAN High - CAN Low 값이 0.9 ~ 5V -> 0을 표현
  
  - CAN High - CAN Low 값이 -0.1 ~ 0.5V -> 1을 표현

- Data 0을 표현 = Dominant
  
  Data 1을 표현  = Recessive

➡**Dominant가 Recessive보다 우선순위가 높다.**

✔ 우선순위가 높다 ➡ 여러 제어기에 동시에 신호 인가되면 <u>우선순위 높은 전압 출력</u>



![](CAN통신01_CAN%20High%20&%20Can%20Low%20signal_assets/2023-02-08-17-07-50-image.png)

- 전압 차를 이용한 방법의 장점: Noise에 강하다

- 장점을 극대화하기 위해서는 전선을 꼬아서 노이즈가 골고루 분배되도록 한다



---

### 강의 요약

- 캔 버스 양 끝단에 120옴 저항 필요

- 혹시 통신이 정상적으로 안된다면 체크하자!



- 캔에서는 데이터를 표현할 떄 CAN High, CAN Low 전압차를 이용하여 표현

- 캔에서는 데이터 0을 Dominant, 데이터 1을 Recessive라고 표현

- 캔에서는 Dominant가 Recessive보다 우선순위높다.






