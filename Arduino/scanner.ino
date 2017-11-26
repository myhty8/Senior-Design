
#include <bluefruit.h>

/* For a list of EIR data types see:
 *    https://www.bluetooth.com/specifications/assigned-numbers/generic-access-profile
 *    Matching enum: cores/nRF5/SDK/components/softdevice/s132/headers/ble_gap.h */

void setup() 
{
  Serial.begin(115200);// baud rate

  Bluefruit.begin(true, true); //enables modes
 
  Bluefruit.setTxPower(4);// max power

  Bluefruit.setName("SD52");

  /* Set the LED interval for blinky pattern on BLUE LED */
  Bluefruit.setConnLedInterval(1000);


  Bluefruit.Scanner.setRxCallback(scan_callback);
  Bluefruit.Scanner.restartOnDisconnect(true);
  Bluefruit.Scanner.setInterval(160, 80);       //standard for finding advertisements
  Bluefruit.Scanner.useActiveScan(true);        
  Bluefruit.Scanner.start(0);                   //lasts forever

}

void scan_callback(ble_gap_evt_adv_report_t* report)
{

  
  //Device address 
   Serial.printBuffer(report->peer_addr.addr, 6, ':');
  Serial.print(" ");

 //RSSI Value
  Serial.printf("%d \n",report->rssi);

  

  

}



void loop() 
{
  
  digitalToggle(LED_RED);

  delay(1000);
}
