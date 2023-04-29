#include "sdcard.hpp"

SDCardWriter::SDCardWriter(){
}

bool SDCardWriter::writeString(String s){
  SD.begin(chipSelect);
  myFile = SD.open("logging.txt", FILE_WRITE);
  if (myFile) {
    myFile.println(s);
    myFile.close();
    return true; 
  }
  return false;
}