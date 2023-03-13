class Sensor{
public:
    virtual double read();
}

class MoistureSensor : Sensor{
private:
    /*const int airValue = 616;   //replace the value with value when placed in air using calibration code
    const int waterValue = 335; //replace the value with value when placed in water using calibration code
    int soilMoistureValue = 0;
    int soilMoisturePercent = 0;*/
public:
    virtual double read() override{
        soilMoistureValue = analogRead(A0);
        //soilMoisturePercent = map(soilMoistureValue, airValue, waterValue, 0, 100);
        return soilMoistureValue;
    }
};

void setup(void)
{
    Serial.begin(9600);
}

void loop(void)
{
    MoistureSensor moistureSensor = new MoistureSensor();
    Serial.println(moistureSensor->read());
    delay(100);
}