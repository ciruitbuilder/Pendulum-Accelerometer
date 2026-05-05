/* 
 * DIY Pendulum Accelerometer
 * Based on the AnalogReadSerial example.
 * Modified by Sanjay Adhinam S to include sensor mapping 
 * and acceleration derivations.
 */
 
const int analogInPin = A2;  // Analog input pin that the potentiometer is attached to

int val = 0;      
int angle = 0;        
float a = 0;
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  val = analogRead(analogInPin);
  angle = map(val, 293, 900, 0, 90);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(val);
  Serial.print("\t angle = ");
  float radian = ((90-angle)*PI)/180;
  Serial.print(90-angle);

  a = 9.81*tan(radian);  // acceleration due to gravity g = 9.81
  Serial.print("\t acceleration = ");
  Serial.println(a);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(200);
}
