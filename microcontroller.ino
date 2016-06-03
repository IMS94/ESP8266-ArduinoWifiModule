String msg;

//setting up
void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
  
  //reset the esp module
  do{
    sendCommand("AT+RST");
    delay(500);
    msg=receiveData();
  }while(msg.indexOf("OK")==-1);
  
  Serial.println(msg);
   
  //set wifi mode to access point
  do{
    sendCommand("AT+CWMODE=2");
    delay(500);
    msg=receiveData();
  }while(msg.indexOf("OK")==-1);
  
  Serial.println(msg);
  
  //start the hotspot
  do{
    sendCommand("AT+CIPMUX=0");
    msg=receiveData();
    delay(100);
   }while(msg.indexOf("OK")==-1);
  
  Serial.println(msg); 
  
  //start the hotspot
  do{
    sendCommand("AT+CWSAP=\"ESP8266\",\"test1234\",5,3");
    msg=receiveData();
    delay(100);
   }while(msg.indexOf("OK")==-1);
  
  Serial.println(msg);
  
  //start the hotspot
  do{
    sendCommand("AT+CIPSEND=1,80");
    msg=receiveData();
    delay(100);
   }while(msg.indexOf("OK")==-1);
  
  Serial.println(msg);
}

// loop
void loop(){
  String response=receiveData();
  Serial.println(response);
  delay(1000);
}


// sends a specific command to the ESP module
void sendCommand(String command){
  Serial1.println(command);
}

//receive data
String receiveData(){
  //wait for something to receive.
  while(Serial1.available()==false);
  String response="";
  while(Serial1.available()){
      response+=Serial1.readStringUntil('\n');
  }
  return response;
}
