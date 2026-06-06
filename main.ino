// #include "SENSORS_MANAGE.h"

/*
NOTE: The Photoresistor, TMP sensor, and Soil Sensors output voltage levels, 
but the ADC pins convert that value to a byte value between 0 to 1023
*/
int A_pins[] = {A0,A1,A2,A3,A4,A5};
int A_pin1 = A0;

int trig=9;
int echo=8;

class analog_Sensors{
  private:

  public:

  float sensor_Read(int Pin){
    int values = analogRead(Pin);
    float voltage = values * (5.0/1024);
    //Serial.println(voltage);
    return voltage;
  }

  float ultrasonic_Sensors(int trig, int echo){
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);    // Used to trigger input pin to start ranging (refer to specs sheet)
    digitalWrite(trig, LOW);
    int duration = pulseIn(echo, HIGH);   // duration in micro seconds
    float inches = 0;
    if(duration>=38000){
      Serial.print("Out range");
      return inches;
      }
    else{
      float distance = duration/58;   // refer to specs sheet for formula
      // distance in centimeters
      inches=distance/2.54;
      return inches;
      }
    }

  float average(float arr[]){
    int len = sizeof(arr);
    float avg = 0;
    for(int i = 0; i < len; i++){
      avg += arr[i];
    }
    float val = avg/len;
    return val;
  }

};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  pinMode(echo, INPUT);
  delay(6000);
  // analog_Sensors sensors;
}

void loop() {
  // put your main code here, to run repeatedly:
  analog_Sensors sensors;
  float light_Sensor1 = sensors.sensor_Read(A_pins[0]);
  float light_Sensor2 = sensors.sensor_Read(A_pins[4]);
  float light_Sensor3 = sensors.sensor_Read(A_pins[5]);
  float light_ARR[] = {light_Sensor1,light_Sensor2,light_Sensor3};
  float light_Sensors_T = sensors.average(light_ARR);


  float tmp_Sensor = sensors.sensor_Read(A_pins[1]);
  tmp_Sensor = ((tmp_Sensor * 1000) - 500)/10;
  tmp_Sensor = (tmp_Sensor * 9/5) + 32;

  float soil_Sensor1 = sensors.sensor_Read(A_pins[2]);
  float soil_Sensor2 = sensors.sensor_Read(A_pins[3]);
  float soil_Sense[] = {soil_Sensor1,soil_Sensor2};
  float soil_Sensors_T = sensors.average(soil_Sense);

  float US_Sensor1 = sensors.ultrasonic_Sensors(trig,echo);

  Serial.println("Light Sensor Value: " + String(light_Sensors_T) + "v");
  Serial.println("Temp Sensor Value: " + String(tmp_Sensor) + "f");
  Serial.println("Soil Sensor Value: " + String(soil_Sensors_T) + "v");
  Serial.println("Ultrasonice Sensor Value: " + String(US_Sensor1)+ " inches");
  Serial.println(" ");
  delay(1000);
}




