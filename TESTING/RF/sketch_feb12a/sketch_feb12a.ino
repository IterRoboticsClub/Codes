#include<VirtualWire.h>

char ch;

void setup()
{
  pinMode(13,OUTPUT);
  vw_set_ptt_inverted(true);
  vw_set_rx_pin(12);
  vw_setup(4000);
  vw_rx_start();
}

void loop() 
{
   uint8_t buf[VW_MAX_MESSAGE_LEN];
   uint8_t buflen = VW_MAX_MESSAGE_LEN;
    
    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
      if(buf[0]=='1')
      { 
         digitalWrite(13,1);
       }  
      else if(buf[0]=='0')
      {
          digitalWrite(13,0);
      }
    }  
}
