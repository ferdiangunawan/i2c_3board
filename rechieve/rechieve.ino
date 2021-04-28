#include <Wire.h>
#include <EasyTransfer.h>

//create object
EasyTransfer ET;

struct RECEIVE_DATA_STRUCTURE {
  //put your variable definitions here for the data you want to receive
  //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
  int16_t visco;
  int16_t density;
};

//give a name to the group of data
RECEIVE_DATA_STRUCTURE mydata;
void setup()
{
  Serial.begin(9600);
  Wire.begin(9); 
  Wire.onReceive(receiveEvent); 
  Wire.onRequest(requestEvent);

  //start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc.
  ET.begin(details(mydata), &Serial);
}

String data = "";

void loop()
{
Serial.println(data);
  //check and see if a data packet has come in.
  if (ET.receiveData()) {
    //this is how you access the variables. [name of the group].[variable name]
    Serial.print("Visco: ");
    Serial.print(mydata.visco);
    Serial.println();
    Serial.print("Density: ");
    Serial.print(mydata.density);
    Serial.println();

  }
  //you should make this delay shorter then your transmit delay or else messages could be lost
  delay(1000);
}

void receiveEvent(int howMany)
{
  data = "";
  while( Wire.available()){
    data += (char)Wire.read();
  }
}

void requestEvent()
{
    Wire.write(data.c_str());
}
