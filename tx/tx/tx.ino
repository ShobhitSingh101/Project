#include <VirtualWire.h>
const int up = 9;
const int left = 8;
const int right = 11;
const int down = 12;

char *data;

void setup() 
{
  Serial.begin(9600);
  pinMode(up,INPUT);
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  pinMode(down,INPUT);
  
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(2);
  vw_setup(2000);
}

void loop()
{
  Serial.print(digitalRead(up));
  Serial.print(digitalRead(left));
  Serial.print(digitalRead(right));
  Serial.println(digitalRead(down));
  
  if(digitalRead(up)==1)
  {
  data="1";
  vw_send((uint8_t *)data, strlen(data));
  vw_wait_tx();
  
  delay(100);
  }
  else if(digitalRead(left)==1)
  {
  data="2";
  vw_send((uint8_t *)data, strlen(data));
  vw_wait_tx();
  
  delay(100);
  }
  else if(digitalRead(right)==1)
  {
  data="3";
  vw_send((uint8_t *)data, strlen(data));
  vw_wait_tx();
  
  delay(100);
  }
  else if(digitalRead(down)==1)
  {
  data="4";
  vw_send((uint8_t *)data, strlen(data));
  vw_wait_tx();
  
  delay(100);
  }

  
  delay(200);
}
