#ifndef SDCARD_HTPP
#define SDCARD_HTPP
#include <SPI.h>
#include <SD.h>
const int chipSelect = 4;


class SDCardWriter{
    public:
        SDCardWriter();
        bool writeString(String); 
    private:
        File myFile;
    };

#endif //SDCARD_HTPP

