#include <VirtualWire.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key;




const int datain = 2;

char c='5';
int count=0;
int count1=0;
int count2=0;

int x=0;
int red1=6;
int yellow1=7;
int green1=8;

int red2=A5;
int yellow2=A4;
int green2=A3;

int red3=A2;
int yellow3=A1;
int green3=A0;

int red4=3;
int yellow4=4;
int green4=5;




unsigned long previousMillis1 = 0; 
unsigned long previousMillis2 = 0; 

int q=0;

void   readrf();
void rfida();
char prev;
void setup() {
  Serial.begin(9600);
 SPI.begin(); 
 rfid.PCD_Init(); // Init MFRC522
  vw_set_ptt_inverted(true);
 vw_set_rx_pin(datain);
 vw_setup(2000);

 vw_rx_start();
 
   pinMode(red1,OUTPUT);
   pinMode(yellow1,OUTPUT);
   pinMode(green1,OUTPUT);
   pinMode(red2,OUTPUT);
   pinMode(yellow2,OUTPUT);
   pinMode(green2,OUTPUT);
   pinMode(red3,OUTPUT);
   pinMode(yellow3,OUTPUT);
   pinMode(green3,OUTPUT);
   pinMode(red4,OUTPUT);
   pinMode(yellow4,OUTPUT);
   pinMode(green4,OUTPUT);
   
   
   Serial.write('5');
   
  // put your setup code here, to run once:

}

void loop() {
   /*unsigned long currentMillis1 = millis();
   if((currentMillis1 - previousMillis2 >= 1000))
  {
    previousMillis2 = currentMillis1;
      readrf();
  }*/

    readrf();
if(count1==0)
{
Serial.print("3");  
delay(1000);
count1=1;
}
if(c=='1' )
{
  count=1;
  count2=1;
}
else if(c=='2')
{
   count=1;
  count2=2;
}
else if(c=='3')
{
  count=1;
count2=3;

}
else if(c=='4')
{
  count=1;
count2=4;

}
else if(c=='5')
{
count2=5;
//Serial.println("hhh");  
}

if(count2==1)
{
   cond1();
}
else if(count2==3)
{
   cond3();
}
else if(count2==2)
{
   cond2();
}
else if(count2==4)
{
   cond4();
}
else if(count2==5)
{
   cond5();
   //Serial.println("zzz");  
}

}

void cond1()
{

  delay(10);
 //  Serial.println(count);
 if(count==1)
  {
    if(x==0)
    {
    Serial.println("1");
      digitalWrite(red1,LOW);
      digitalWrite(yellow1,HIGH);
      digitalWrite(green1,LOW);
      digitalWrite(red2,LOW);
      digitalWrite(yellow2,HIGH);
      digitalWrite(green2,LOW);
      digitalWrite(red3,LOW);
      digitalWrite(yellow3,HIGH);
     digitalWrite(green3,LOW);
      digitalWrite(red4,LOW);
      digitalWrite(yellow4,HIGH);
     digitalWrite(green4,LOW);
     
     delay(3000);
    count=0;
    x=1;
    }
      }
  if(count==1)
  {
    if(x==1)
    {
   // Serial.println("else1");
  digitalWrite(red1,LOW);
 digitalWrite(yellow1,LOW);
 digitalWrite(green1,HIGH);
 digitalWrite(red2,HIGH);
 digitalWrite(yellow2,LOW);
 digitalWrite(green2,LOW);
 digitalWrite(red3,HIGH);
 digitalWrite(yellow3,LOW);
 digitalWrite(green3,LOW);
 digitalWrite(red4,HIGH);
 digitalWrite(yellow4,LOW);
 digitalWrite(green4,LOW);
q=1;
//readrf();
rfida();
}
  }
 
}

void cond2()
{
  delay(10);
  // Serial.println(count);
 if(count==1)
  {
    if(x==0)
    {
   Serial.println("2");
      digitalWrite(red1,LOW);
      digitalWrite(yellow1,HIGH);
      digitalWrite(green1,LOW);
      digitalWrite(red2,LOW);
      digitalWrite(yellow2,HIGH);
      digitalWrite(green2,LOW);
      digitalWrite(red3,LOW);
      digitalWrite(yellow3,HIGH);
     digitalWrite(green3,LOW);
      digitalWrite(red4,LOW);
      digitalWrite(yellow4,HIGH);
     digitalWrite(green4,LOW);
     
     delay(3000);
     x=1;
    count=0;
      }
  }
  if(count==1)
  {
    if(x==1)
    {
  
  //  Serial.println("else2");
  digitalWrite(red1,HIGH);
 digitalWrite(yellow1,LOW);
 digitalWrite(green1,LOW);
 digitalWrite(red2,LOW);
 digitalWrite(yellow2,LOW);
 digitalWrite(green2,HIGH);
 digitalWrite(red3,HIGH);
 digitalWrite(yellow3,LOW);
 digitalWrite(green3,LOW);
 digitalWrite(red4,HIGH);
 digitalWrite(yellow4,LOW);
 digitalWrite(green4,LOW);
 q=3;
//readrf();
rfida();
}
  }
}

void cond3()
{
  delay(10);
  // Serial.println(count);
  if(count==1)
  {
    if(x==0)
    {
  Serial.println("3");
      digitalWrite(red1,LOW);
      digitalWrite(yellow1,HIGH);
      digitalWrite(green1,LOW);
      digitalWrite(red2,LOW);
      digitalWrite(yellow2,HIGH);
      digitalWrite(green2,LOW);
      digitalWrite(red3,LOW);
      digitalWrite(yellow3,HIGH);
     digitalWrite(green3,LOW);
      digitalWrite(red4,LOW);
      digitalWrite(yellow4,HIGH);
     digitalWrite(green4,LOW);
     
     delay(3000);
     x=1;
    count=0;
      }
  }
  if(count==1)
  {
    if(x==1)
    {
  //  Serial.println("else2");
  digitalWrite(red1,HIGH);
 digitalWrite(yellow1,LOW);
 digitalWrite(green1,LOW);
 digitalWrite(red2,HIGH);
 digitalWrite(yellow2,LOW);
 digitalWrite(green2,LOW);
 digitalWrite(red3,LOW);
 digitalWrite(yellow3,LOW);
 digitalWrite(green3,HIGH);
 digitalWrite(red4,HIGH);
 digitalWrite(yellow4,LOW);
 digitalWrite(green4,LOW);
 q=5;
//readrf();
rfida();
}
  }
}

void cond4()
{
  delay(10);
  // Serial.println(count);
  if(count==1)
  {
    if(x==0)
    {
    Serial.println("4");
      digitalWrite(red1,LOW);
      digitalWrite(yellow1,HIGH);
      digitalWrite(green1,LOW);
      digitalWrite(red2,LOW);
      digitalWrite(yellow2,HIGH);
      digitalWrite(green2,LOW);
      digitalWrite(red3,LOW);
      digitalWrite(yellow3,HIGH);
     digitalWrite(green3,LOW);
      digitalWrite(red4,LOW);
      digitalWrite(yellow4,HIGH);
     digitalWrite(green4,LOW);
     
     delay(3000);
     x=1;
    }
     }
  if(count==1)
  {
    if(x==1)
    {
  //  Serial.println("else2");
  digitalWrite(red1,HIGH);
 digitalWrite(yellow1,LOW);
 digitalWrite(green1,LOW);
 digitalWrite(red2,HIGH);
 digitalWrite(yellow2,LOW);
 digitalWrite(green2,LOW);
 digitalWrite(red3,HIGH);
 digitalWrite(yellow3,LOW);
 digitalWrite(green3,LOW);
 digitalWrite(red4,LOW);
 digitalWrite(yellow4,LOW);
 digitalWrite(green4,HIGH);
    
    q=7;
//readrf();
rfida();
}
}
}

void cond5()
{
   readrf();

   unsigned long currentMillis = millis();

     if((q==0) && (currentMillis - previousMillis1 >= 3000))
  {
 readrf();
 previousMillis1 = currentMillis;
// Serial.println("p:"+String(previousMillis1));
 //erial.println("c:"+String(currentMillis));
 digitalWrite(red1,LOW);
 digitalWrite(yellow1,LOW);
 digitalWrite(green1,HIGH);
 digitalWrite(red2,HIGH);
 digitalWrite(yellow2,LOW);
 digitalWrite(green2,LOW);
 digitalWrite(red3,HIGH);
 digitalWrite(yellow3,LOW);
 digitalWrite(green3,LOW);
 digitalWrite(red4,HIGH);
 digitalWrite(yellow4,LOW);
 digitalWrite(green4,LOW);
 
 q=1;
  }
  else if((q==1) && (currentMillis - previousMillis1 >= 9000))
  {
 readrf();
previousMillis1 = currentMillis;
//Serial.println("p:"+String(previousMillis1));
// Serial.println("c:"+String(currentMillis));
  digitalWrite(red1,LOW);
 digitalWrite(yellow1,HIGH);
 digitalWrite(green1,LOW);
 digitalWrite(red2,LOW);
 digitalWrite(yellow2,HIGH);
 digitalWrite(green2,LOW);
 digitalWrite(red3,HIGH);
 digitalWrite(yellow3,LOW);
 digitalWrite(green3,LOW);
 digitalWrite(red4,HIGH);
 digitalWrite(yellow4,LOW);
 digitalWrite(green4,LOW);
 

q=2;
  }
  else if((q==2) && (currentMillis - previousMillis1 >= 3000))
  { readrf();
 //Serial.println("3");
previousMillis1 = currentMillis;
//Serial.println("p:"+String(previousMillis1));
// Serial.println("c:"+String(currentMillis));
   digitalWrite(red1,HIGH);
 digitalWrite(yellow1,LOW);
 digitalWrite(green1,LOW);
 digitalWrite(red2,LOW);
 digitalWrite(yellow2,LOW);
 digitalWrite(green2,HIGH);
 digitalWrite(red3,HIGH);
 digitalWrite(yellow3,LOW);
 digitalWrite(green3,LOW);
 digitalWrite(red4,HIGH);
 digitalWrite(yellow4,LOW);
 digitalWrite(green4,LOW);
 
q=3;
  }
    else if((q==3) && (currentMillis - previousMillis1 >= 9000))
  { readrf();
 //Serial.println("3");
previousMillis1 = currentMillis;
//Serial.println("p:"+String(previousMillis1));
 //Serial.println("c:"+String(currentMillis));
   digitalWrite(red1,HIGH);
 digitalWrite(yellow1,LOW);
 digitalWrite(green1,LOW);
 digitalWrite(red2,LOW);
 digitalWrite(yellow2,HIGH);
 digitalWrite(green2,LOW);
 digitalWrite(red3,LOW);
 digitalWrite(yellow3,HIGH);
 digitalWrite(green3,LOW);
 digitalWrite(red4,HIGH);
 digitalWrite(yellow4,LOW);
 digitalWrite(green4,LOW);
 
q=4;
  }
  else if((q==4) && (currentMillis - previousMillis1 >= 3000))
  { readrf();
 //Serial.println("3");
previousMillis1 = currentMillis;
//Serial.println("p:"+String(previousMillis1));
 //Serial.println("c:"+String(currentMillis));
   digitalWrite(red1,HIGH);
 digitalWrite(yellow1,LOW);
 digitalWrite(green1,LOW);
 digitalWrite(red2,HIGH);
 digitalWrite(yellow2,LOW);
 digitalWrite(green2,LOW);
 digitalWrite(red3,LOW);
 digitalWrite(yellow3,LOW);
 digitalWrite(green3,HIGH);
 digitalWrite(red4,HIGH);
 digitalWrite(yellow4,LOW);
 digitalWrite(green4,LOW);
 
q=5;
  }
   else if((q==5) && (currentMillis - previousMillis1 >= 9000))
  { readrf();
// Serial.println("3");
previousMillis1 = currentMillis;
//Serial.println("p:"+String(previousMillis1));
 //Serial.println("c:"+String(currentMillis));
   digitalWrite(red1,HIGH);
 digitalWrite(yellow1,LOW);
 digitalWrite(green1,LOW);
 digitalWrite(red2,HIGH);
 digitalWrite(yellow2,LOW);
 digitalWrite(green2,LOW);
 
 digitalWrite(red3,LOW);
 digitalWrite(yellow3,HIGH);
 digitalWrite(green3,LOW);
 digitalWrite(red4,LOW);
 digitalWrite(yellow4,HIGH);
 digitalWrite(green4,LOW);
 
q=6;
  }
    else if((q==6) && (currentMillis - previousMillis1 >= 3000))
  { readrf();
// Serial.println("3");
previousMillis1 = currentMillis;
//Serial.println("p:"+String(previousMillis1));
 //Serial.println("c:"+String(currentMillis));
   digitalWrite(red1,HIGH);
 digitalWrite(yellow1,LOW);
 digitalWrite(green1,LOW);
 digitalWrite(red2,HIGH);
 digitalWrite(yellow2,LOW);
 digitalWrite(green2,LOW);
 digitalWrite(red3,HIGH);
 digitalWrite(yellow3,LOW);
 digitalWrite(green3,LOW);
 digitalWrite(red4,LOW);
 digitalWrite(yellow4,LOW);
 digitalWrite(green4,HIGH);
 
q=7;
  }
   else if((q==7) && (currentMillis - previousMillis1 >= 9000))
  { readrf();
 //Serial.println("3");
previousMillis1 = currentMillis;
//Serial.println("p:"+String(previousMillis1));
 //Serial.println("c:"+String(currentMillis));
   digitalWrite(red1,LOW);
 digitalWrite(yellow1,HIGH);
 digitalWrite(green1,LOW);
 digitalWrite(red2,HIGH);
 digitalWrite(yellow2,LOW);
 digitalWrite(green2,LOW);
 digitalWrite(red3,HIGH);
 digitalWrite(yellow3,LOW);
 digitalWrite(green3,LOW);
 digitalWrite(red4,LOW);
 digitalWrite(yellow4,HIGH);
 digitalWrite(green4,LOW);
 
q=0;
  }
   readrf();
}

void readrf()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
 uint8_t buflen = VW_MAX_MESSAGE_LEN; 
 
 if (vw_get_message(buf, &buflen))
 {
 Serial.println(buf[0]);
 delay(100);
 if(buf[0]=='1')
 { 
  c='1';
 } 
 else if(buf[0]=='2')
 {
 c='2';
 }
 else if(buf[0]=='3')
 {
 c='3';
 }
 else if(buf[0]=='4')
 {
 c='4';
 }
 else if(buf[0]=='5')
 {
 c='5';
 }
 
 
 }
}

void rfida()
{
  /*readrf();
  if (rfid.isCard()) {
        if (rfid.readCardSerial()) {
            Serial.println(rfid.serNum[0]);
       Serial.println("hh");
       c='5';
       x=0;
          }
    }

    rfid.halt();
    delay(10);*/
    if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return; 
    Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));

    if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  } 
  Serial.println( rfid.uid.uidByte[0]);
 rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
   // rfid.halt();
   if( rfid.uid.uidByte[0]==230)
   {
    Serial.println("hi");
   c='5';
   x=0;
   }
    delay(10);
  // put your main code here, to run repeatedly:

}
