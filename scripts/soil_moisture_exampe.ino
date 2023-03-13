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


class LightSensor : Sensor{
private:
    int value_A0;
    bool value_D7;
public:
    virtual double read() override{
        value_A0 =analogRead(A0); // reads the analog input from the IR distance sensor
        value_D7 = digitalRead(7);

        /*Serial.println(value_A0);
        Serial.println(value_D7);*/

        return value_A0

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
    LightSensor lightSensor = new LightSensor();
    Serial.println(lightSensor->read());
    delay(100);
}
