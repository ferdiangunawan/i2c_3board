#include <EasyTransfer.h>

//create object
EasyTransfer ET; 

struct SEND_DATA_STRUCTURE{
  //put your variable definitions here for the data you want to send
  //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
  int16_t visco;
  int16_t density;
};

//give a name to the group of data
SEND_DATA_STRUCTURE mydata;

void setup(){
  Serial.begin(9600);
  //start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc.
  ET.begin(details(mydata), &Serial);
  
}

void loop(){
  //this is how you access the variables. [name of the group].[variable name]
  mydata.visco = random(2,27);
  mydata.density = random(8,1000);
  //send the data
  ET.sendData();
 
//  Serial.println(mydata.visco);
//  Serial.println(mydata.density);
  
  delay(5000);
}
