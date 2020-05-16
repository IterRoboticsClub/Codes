#include <VirtualWire.h>
char *ch;

void setup()
{
Serial.begin(9600);
pinMode(13,OUTPUT);
vw_set_ptt_inverted(true);
vw_set_tx_pin(12);
vw_setup(4000); //Transfer at 4000 Kbps
}

void loop()
{
  char ch;
  int len;
  ch=Serial.read();
 while(!Serial.available())
 {
   ch=Serial.read();
 }
 len=strlen(ch);
 vw_send((uint8_t )ch, len);
 vw_wait_tx();
 digitalWrite(13,1);
 delay(100);
 Serial.print(ch);
}
