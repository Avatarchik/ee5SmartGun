#include "wirelessDataTransfer.h"
#include "config.h"

IPAddress IPaddr(IP_Address);
WiFiUDP Udp;

int setupWifi()
{
  //WiFi.mode(WIFI_STA);
	WiFi.begin(STASSID, STAPSK);
	while (WiFi.status() != WL_CONNECTED) {
		delay(500);
	}
	return 1;
}

void printWifiInfo()
{
    Serial.println("Connected! IP address: ");
    Serial.println(WiFi.localIP());
    Serial.printf("UDP server on port %d\n", localPort);  
}

void setupUDP()
{
  Udp.begin(localPort);
}

int sendUDP()
{
  //Serial.println("sendUDP: begin");
  
	if(Udp.beginPacket(IPaddr, localPort))
  {   
	  for (int i = 0; i < PACKET_SIZE; i++) {
		  Udp.write(sendData[i]);           
	  }

	  if (!Udp.endPacket()){ 
	   #ifdef DEBUGUDP
	   Serial.println("UDP endpacket FAILED");
     #endif
	  }
     yield();
  }
  else
  {
    #ifdef DEBUGUDP
    Serial.println("UDP beginpacket FAILED");                    
    #endif
  }
  //Serial.println("sendUDP: end");
  return 1;
}

void checkWifi()
{
  if (WiFi.status() != WL_CONNECTED)
        {
            Serial.println("WIFI HAS BEEN DISCONNECTED... RESETTING NOW");
            //if (setupWifi())
            //    printWifiInfo();
            
        } 
}
