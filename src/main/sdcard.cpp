#include "sdcard.hpp"

SDCardWriter::SDCardWriter(){
  SD.begin(chipSelect);
  this -> myFile = SD.open("logging.txt", FILE_WRITE);
}
bool SDCardWriter::writeString(String s){
  if (myFile) {
    myFile.println(s);
    myFile.close();
    return true; 
  }
  return false;
}