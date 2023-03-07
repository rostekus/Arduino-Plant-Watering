const int IN_A0 = A0; // analog input
const int IN_D0 = 8; // digital input

void setup() {
  pinMode (IN_A0, INPUT);
  pinMode (IN_D0, INPUT);
  Serial.begin(9600);
}

int value_A0;
bool value_D7;

void loop() {
 
  value_A0 =analogRead(A0); // reads the analog input from the IR distance sensor
  value_D7 = digitalRead(7);
 Serial.println("hello");
 Serial.println(value_A0);
  Serial.println(value_D7);

 delay(1000);

}
 
