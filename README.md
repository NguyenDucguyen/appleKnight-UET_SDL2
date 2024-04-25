# **THE KING AND THE THIEF-SHOWTIME-UET K68J**



# GIỚI THIỆU GAME 

the king and the thief là game thuộc thể loại thử thách , bạn sẽ phải cố gắng tiêu diệt nhà vua độc tài bằng cách sử dụng chiếc kiếm tích đủ nội năng để ám sát
Đây là game lấy nguồn cảm hứng từ 2 tựa game :
_Game ÁM SÁT NHÀ VUA trên gamevui về lối chơi: [https://gamevivu.net/am-sat-nha-vua-2/]
_Game Dead cell về thiết kế nhân vật cùng background 



# 1. BẮT ĐẦU GAME 
![background](https://hackmd.io/_uploads/H1WkqCDWR.jpg)

nhấn vào nút **play** để vào game, **quit** để thoát game 
và sau đó người chơi sẽ đươc vào game 

# 2. CÁC THÀNH PHẦN TRONG GAME

**a) nhân vật **THE KING** :**
 
![Idle](https://hackmd.io/_uploads/By9q6CDWA.png)
là tên độc tài reo rắc nỗi sợ cho người dân , là đối tựợng cần thủ tiêu của nhân vật chính 

**b) nhân vật THE THIEF :**

![Idle](https://hackmd.io/_uploads/Sk6SA0DbA.png)
là niềm hi vọng , cứu rỗi mọi người khỏi ách đô hộ của tên độc tài THE KING 
*được lấy cảm hứng từ nhân vật chính trong game DEAD CELL :

![th](https://hackmd.io/_uploads/H1kiU1ObR.jpg)


**c) thanh nội lực**
![slider](https://hackmd.io/_uploads/HJ4vyJdbC.png)
khi tích đầy nội lực , sức mạnh của THE THIEF được giải phóng , khi đó có thể tiêu diệt THE KING 
![Attack](https://hackmd.io/_uploads/B1ywxJ_-C.png)

**d) các thành phần khác**

để vào game :![txtPlay](https://hackmd.io/_uploads/S1EhxJ_W0.png)
và để thoát game : ![txtQuit](https://hackmd.io/_uploads/SJI6xyd-C.png)

tượng thần chèn vào menu : ![Salt](https://hackmd.io/_uploads/B1DuZyub0.png)


background : được cấu thành từ nhiều ảnh 
![BG1](https://hackmd.io/_uploads/HkpcbyuWR.png)
![BG2](https://hackmd.io/_uploads/ByJUMk_WC.png)
![BG3](https://hackmd.io/_uploads/r1lDM1OZR.png)

# 3.CÁCH ĐỂ CHƠI :

_nhân vật THE THIEF liên tục đuổi  theo nhân vật THE KING để theo dõi và ám sát 
![Run](https://hackmd.io/_uploads/BJ8eEJO-C.png)
và nhân vật THE KING có thể quay lại nhìn để kiểm tra xem THE THIEF có động tĩnh 
và khi nhân vật THE THIEF tích đủ nội năng để tiêu diệt nhân vật THE KING:
![slider](https://hackmd.io/_uploads/SyJSHk_Z0.png) ![Attack](https://hackmd.io/_uploads/SJWDSyOZC.png)
![Death](https://hackmd.io/_uploads/rJKtByOb0.png)
hoặc khi chưa tích đủ nội năng mà bị phát hiện , THE THIEF sẽ bị THE KING tiêu diệt : 
![Attack](https://hackmd.io/_uploads/H1_xU1uZR.png)
![Death](https://hackmd.io/_uploads/rysbL1O-0.png)
và khi tiêu diệt được THE KING , ta sẽ quay trở lại màn hình menu để chơi lại 

# 
# VỀ SOURCE CODE GAME :
**về code **
* CommonFunc : nơi lưu giữ thư viện của game và các thông số mặc định của game 
* Texture 2D : vẽ hình ảnh lên màn hình máy tính , sử dụng thêm SDL_Rendererflip để lật ảnh nhân vật vua;
* Math : trả lại một giá trị trong khoảng từ min đến max 
* Vector2D : lưu vị trí của các vật (nhân vật THE KING , THE THIEF , các Button ,slider,...) 
* Button : click để vào game và thoát game
* Slider : là thanh nộ của nhân vật THE THIEF , mỗi lần nhấn nút ENTER nó sẽ tăng giá trị lên , nếu ta thả tay quá lâu nó sẽ tụt xuống trở lại như cũ . Khi đầy sẽ mất một lúc cho nhân vật THE THIEF có thể rút kiếm tiêu diệt THE KING 
* Background : nơi load ảnh background cùng menu; background và menu giống nhau về phần khung tổng quát , khác nhau giữa bức tượng ở menu và nền đất chạy ở background 
* KING : file code tạo lên nhân vật THE KING 
* PLAYER : file code tạo lên nhân vật THE THIEF
* main : file chính khởi tạo SDL,đóng SDL, âm thanh , hàm play , hàm menu,..
**các file khác : ** 
src : lưu các include, lib của SDL;
images : lưu ảnh ;
sounds : lưu âm thanh background ;


 
