# **THE KING AND THE THIEF-SHOWTIME-UET K68J**



# GIỚI THIỆU GAME 

the king and the thief là game thuộc thể loại thử thách , bạn sẽ phải cố gắng tiêu diệt nhà vua độc tài bằng cách sử dụng chiếc kiếm tích đủ nội năng để ám sát
Đây là game lấy nguồn cảm hứng từ 2 tựa game :
_Game ÁM SÁT NHÀ VUA trên gamevui về lối chơi: [https://gamevivu.net/am-sat-nha-vua-2/]
_Game Dead cell về thiết kế nhân vật cùng background 



# 1. BẮT ĐẦU GAME 
![síuii](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/bcb0f340-cf4d-429c-8487-3582e07f0487)


nhấn vào nút **play** để vào game, **quit** để thoát game 
và sau đó người chơi sẽ đươc vào game 

# 2. CÁC THÀNH PHẦN TRONG GAME

**a) nhân vật **THE KING** :**
 ![Idle](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/fdf81532-ddc3-46ca-9c80-b57056df0222)

là tên độc tài reo rắc nỗi sợ cho người dân , là đối tựợng cần thủ tiêu của nhân vật chính 

**b) nhân vật THE THIEF :**
![Idle](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/82ecea93-0733-44b2-8bef-345707dc8d9c)


là niềm hi vọng , cứu rỗi mọi người khỏi ách đô hộ của tên độc tài THE KING 
*được lấy cảm hứng từ nhân vật chính trong game DEAD CELL :

![th](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/dbb8827c-e954-47c7-9ef0-c456eff1e11a)



**c) thanh nội lực**






![slider](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/13a0269b-b6c5-4374-8e7b-6189c1570677)

khi tích đầy nội lực , sức mạnh của THE THIEF được giải phóng , khi đó có thể tiêu diệt THE KING 
![Attack](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/df580135-2a05-48ca-a1d4-d3fd4747a613)

**d) các thành phần khác**

để vào game : 
![txtPlay](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/bedae446-442f-4e0d-a9e9-3b094fdf692b)

và để thoát game :
![txtQuit](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/944b1226-fffa-44b3-921b-1fb070acd231)


tượng thần chèn vào menu : 
![Salt](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/653699d4-8488-4764-ab0d-fe3c7747d50d)



background : được cấu thành từ nhiều ảnh 

![BG1](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/ba5215a5-73f5-4f21-bbc5-e562e56bc897)
![BG2](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/f03fc57b-b207-4f10-b0be-e0e7a4bbacb4)
![BG3](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/25a197b0-418d-4c4c-84eb-225a270150cc)


# 3.CÁCH ĐỂ CHƠI :

_nhân vật THE THIEF liên tục đuổi  theo nhân vật THE KING để theo dõi và ám sát 

![Run](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/cc286354-d889-4980-92dd-af2cb46be078)




và nhân vật THE KING có thể quay lại nhìn để kiểm tra xem THE THIEF có động tĩnh 
và khi nhân vật THE THIEF tích đủ nội năng để tiêu diệt nhân vật THE KING:

![slider](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/6637d74d-8a91-4bb5-9885-49cadf5efce9)
![Attack](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/d8675652-62d8-4272-b49e-e4655a411fdc)
![Death](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/562604f7-839e-4892-95aa-d243a71184aa)





hoặc khi chưa tích đủ nội năng mà bị phát hiện , THE THIEF sẽ bị THE KING tiêu diệt : 

![Attack](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/af953e52-a158-421b-acd9-87a04011889d)
![Death](https://github.com/NguyenDucguyen/appleKnight-UET_SDL2/assets/160694563/bb6222ab-de2e-493a-9264-345b0fca8132)
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


 

