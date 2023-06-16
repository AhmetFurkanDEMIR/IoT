// 19010011019
// Ahmet Furkan DEMIR

/* PORT AYARLAMALARI*/
#define PIN_TRIG 5
#define PIN_ECHO 4
#define BUZZER 6
#define PIR 12
#define RED  16
#define GREEN  17
#define BLUE  18

int distance;
int duration;
int pirValue;

void setup() 
{

  //Seriport aktiflestirme
  Serial1.begin(115200);
  Serial1.println("NESNELERİN İNTERNETİ DERSİ - PROJE ÖDEVİ");

  //HC-SR04 PIN AYARLAMALARI
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  //BUZZER PIN AYARLAMASI - MOD : CIKIS
  pinMode(BUZZER, OUTPUT);

  //RGB LED PIN AYARLAMASI - MOD : CIKIS
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  //PIR SENSORU PIN AYARLAMASI - MOD : GIRIS
  pinMode(PIR, INPUT);

  //TEST ISLEMLERI

  /*
  RGB Led ortak anot olduğu için voltaj sabit ve  LOW(1) da yanar HIGH(0) da söner.
  */

  //LEDLERI YAK
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  
  //BUZZER TEST
  digitalWrite(BUZZER, HIGH);
  delay(1000);
  digitalWrite(BUZZER, LOW);

  //LEDLERI SONDUR
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  
}

void loop() {

  //PIR sensorunden deger okuma
  pirValue = digitalRead(PIR);
  Serial1.println("PIR Value : ");
  Serial1.println(pirValue);

  /* PIR dan gelen deger 1 ise aktif bir hareket var ise */
  if(pirValue==1)
  {

    Serial1.println("<< Hareket Algılandı >> ");
    //HC Mesafe Sensorunu oku
    digitalWrite(PIN_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_TRIG, LOW);

    /* 
      Mesafe sensorunden gelen degeri formulize ediyoruz.
    */
    duration = pulseIn(PIN_ECHO, HIGH);
    distance = duration / 59;
    Serial1.println("Distance");
    Serial1.println(distance);

    if (distance > 200)
    {
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(BLUE, HIGH);
      digitalWrite(BUZZER, LOW);
    }
    else
    //Mesafe 100 cm den büyükse - 200 cm den kücükse Led ve buzzer islemleri
    if((distance <= 200) && (distance>100))
    {
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, HIGH);
      digitalWrite(BLUE, LOW);
      digitalWrite(BUZZER, LOW);
    }
    else
    //Mesafe 100 cm den kücükse Led ve buzzer islemleri
    if(distance<=100)
    {
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, HIGH);
      digitalWrite(BLUE, HIGH);
      digitalWrite(BUZZER, HIGH);
    }
  }
  else
  {
    /* 
      PIR dan gelen deger 0 ise hareket yok ise 
      HC Mesafe sensorunu okumuyoruz.
      Ledleri ve Buzzeri kapatıyoruz.
    */
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, HIGH);
    digitalWrite(BUZZER, LOW);
  }
  delay(200);
}