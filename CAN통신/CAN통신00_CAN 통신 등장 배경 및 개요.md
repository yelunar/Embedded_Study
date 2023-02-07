# CAN 통신00

### CAN 통신 등장 배경 및 개요

현재 자동차 내부에는 다양한 전자 장치 존재

이러한 장치를 control 하는 컴퓨터가 각각 존재 이것을 -> `제어기` 라고 부름

<img src="file:///C:/Users/SSAFY/AppData/Roaming/marktext/images/2023-02-06-17-12-33-image.png" title="" alt="" width="596">

2사분면의 초록색 칩안에 3사분면의 칩이 들어감

제어기 sw 다운로드하면 제어기가 실행됨

이것을 그대로 넣으면 고온, 수분 등에 의해 파손되기 쉬움 -> 4사분면 케이스에 넣어 보관

<img src="file:///C:/Users/SSAFY/AppData/Roaming/marktext/images/2023-02-06-17-14-54-image.png" title="" alt="" width="618">

자동차 내부에는 이러한 제어기가 곳곳에 탑재되어 있음

**이러한 장치가 점점 늘어나면서 이런 제어기끼리 정보를 주고 받을 필요성 커짐**

✔ 정보를 주고 받는다 ➡ <u>통신을 한다</u>

    통신에도 여러가지 종류가 있는데 (TCP, Wifi 등.. ) 각 상황에 맞게 알맞은 통신 사용

    제어기들끼리 통신을 하려면 차량 사양과 딱 맞는 통신 필요 ➡ **CAN 통신 등장!**

> CAN : Controller Area Network
