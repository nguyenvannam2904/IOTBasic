void setup(){ 
  Serial.begin(9600);
}

void loop()
{  
  int sensorValue;

 sensorValue=analogRead(A0);
 Serial.print("The voltage value:");
 Serial.print(sensorValue*5000/1023.0);
 Serial.println("mV");
 delay(200);
 Serial.print("\n");
}