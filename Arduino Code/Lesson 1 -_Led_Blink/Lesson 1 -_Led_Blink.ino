/*
  Blink - Nhấp nháy
  Đoạn code làm nhấp nháy một đèn LED cho trước
 */
 
// chân digital 13 cần được kết nối với đèn LED
// và chân digital 13 này sẽ được đặt tên là 'led'. Biến 'led' này có kiểu dữ liệu là int và có giá trị là 13
int led = 13;
 
// Hàm setup chạy một lần duy nhất khi khởi động chương trình
void setup() {                
  // đặt 'led' là OUTPUT
  pinMode(led, OUTPUT);    
}
 
// Hàm loop chạy mãi mãi sau khi kết thúc hàm setup()
void loop() {
  digitalWrite(led, HIGH);   // bật đèn led sáng
  delay(500);               // dừng chương trình trong 1 giây => thây đèn sáng được 1 giây
  digitalWrite(led, LOW);    // tắt đèn led
  delay(500);               // dừng chương trình trong 1 giây => thấy đèn tối được 1 giây
}
