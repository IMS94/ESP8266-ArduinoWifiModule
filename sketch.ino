String msg;

//setting up
void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
  
  sendSetupCommand("AT+RST");   
  sendSetupCommand("AT+CWMODE=3");
  sendSetupCommand("AT+CWJAP=\"AndroidAP\",\"12345678\"");
  sendSetupCommand("AT+CIPMUX=1");
  sendSetupCommand("AT+CIPSERVER=1,8080");
}

// loop
void loop(){
  if(Serial1.available()){
    String message=Serial1.readStringUntil('\n');
    Serial.println(message);
    String command=extract(message);
    process(command);
  }
}


// sends a specific command to the ESP module
void sendSetupCommand(String command){
  //set wifi mode to access point
  do{
    Serial1.println(command);
    delay(1000);
    msg=receiveData();
  }while(msg.indexOf("OK")==-1);
  Serial.println(msg);
  delay(3000);
}

//receive data
String receiveData(){
  String response="";
  while(Serial1.available()==false);
  while(Serial1.available()){
      response+=Serial1.readStringUntil('\n');
  }
  return response;
}

String extract(String message){
  if(message.indexOf("+IPD")>=0){
    int start=message.indexOf(':');
    if(start<0){
      return "";
    }
    String cmd= message.substring(start+1);
    Serial.println(cmd);
    return cmd;
  }
  return "";
}

//process the received command
void process(String s){
  if(s=="") return;
  for(int i=0; i<s.length(); i++)
  {
    if(s[i] == 'f'){
    
    }
    else if(s[i] == 'b'){
    
    }
    else if(s[i] == 's'){
    
    }
    else if(s[i] == 'l'){
    
    }
    else if(s[i] == 'r'){
    
    }  
  }
}
