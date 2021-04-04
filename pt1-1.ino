#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <VarSpeedServo.h>
VarSpeedServo sv1;
VarSpeedServo sv2;
VarSpeedServo sv3;

int bt1 = 7;

int bt2 = 6;
int i  = 0;
int val1 = 0;
#define SCREEN_WIDTH 128 // pixel ความกว้าง
#define SCREEN_HEIGHT 64 // pixel ความสูง 

// กำหนดขาต่อ I2C กับจอ OLED
#define OLED_RESET     -1 //ขา reset เป็น -1 ถ้าใช้ร่วมกับขา Arduino reset
Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int var = 0; // ตัวแปรสำหรับทดสอบแสดงผล
void setup() {

  sv1.attach(10);
  sv2.attach(9);
  sv3.attach(8);
  pinMode(bt1, INPUT);
  pinMode(bt2, INPUT);
  Serial.begin(9600);
  if (!OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // สั่งให้จอ OLED เริ่มทำงานที่ Address 0x3C
    Serial.println("SSD1306 allocation failed");
  } else {
    Serial.println("ArdinoAll OLED Start Work !!!");
  }
}

void loop() {
  if (digitalRead(bt1) == HIGH) {
    delay(50);
    if (digitalRead(bt1) == LOW) {
      i += 1;
      while (i == 1) {
        OLED.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
        OLED.setTextColor(WHITE, BLACK);  //กำหนดข้อความสีขาว ฉากหลังสีดำ
        OLED.setCursor(0, 0); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
        OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
        OLED.println("MODE 1"); // แสดงผลข้อความ ALL
        OLED.display();
        if (digitalRead(bt1) == HIGH) {
          delay(50);
          if (digitalRead(bt1) == LOW) {
            i = 2;
          }
        }
        if (digitalRead(bt2) == HIGH) {
          delay(100);
          while (digitalRead(bt2) == LOW) {
            OLED.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
            OLED.setTextColor(WHITE, BLACK);  //กำหนดข้อความสีขาว ฉากหลังสีดำ
            OLED.setCursor(0, 0); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
            OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
            OLED.println("DO MODE 1"); // แสดงผลข้อความ ALL
            OLED.setCursor(00, 20); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
            OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
            OLED.println("!!DANGER!!"); // แสดงผลข้อความ ALL
            OLED.display();
            delay(300);

            OLED.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
            OLED.display();
            delay(300);
            

          }
        }
      }





      if (i > 5) {
        i = 0;
      }
    }
  }

  OLED.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
  OLED.setTextColor(WHITE, BLACK);  //กำหนดข้อความสีขาว ฉากหลังสีดำ
  OLED.setCursor(0, 20); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
  OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
  OLED.println("MODE"); // แสดงผลข้อความ ALL
  OLED.setCursor(60, 20); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
  OLED.setTextSize(2); // กำหนดขนาดตัวอักษร
  OLED.println(i); // แสดงผลข้อความ ALL
  OLED.display();
}
