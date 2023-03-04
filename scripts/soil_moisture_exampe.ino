const int dry = 595; // value for dry sensor
const int wet = 239; // value for wet sensor

void setup(void)
{
    Serial.begin(9600);
}

void loop(void)
{
    int sensorVal = analogRead(A0);
    int percentageHumididy = map(sensorVal, wet, dry, 100, 0);
    Serial.print(percentageHumididy);
    Serial.println("%");
    delay(100);
}