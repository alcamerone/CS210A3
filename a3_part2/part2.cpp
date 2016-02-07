#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

void convertToUintvars(int inputArray[], int numOfValues){
     for(int i = 0; i < numOfValues; i++){
             inputArray[i] = inputArray[i] & 127;
     }
     return;
}

string convertToOutputString(int inputArray[], int numOfValues){
       string outputString = "";
       char zero = 0;
       char one = 1;
       for(int i = 0; i < numOfValues && inputArray[i] != -1; i++){
            for(int bit = 64; bit > 0; bit = bit/2){
                    if(inputArray[i] & bit){
                                     outputString = outputString + one;
                    }else{
                                     outputString = outputString + zero;
                    }
            }
       }
       return outputString;
}

int convertToUintvarOutput(string outputString){
    int output = 0;
    int power = 0;
    for(int i = outputString.size() - 1; i > -1; i--){
            if(outputString[i] == 1){
                               output += pow(2.0, power);
            }
            power++;
    }
    return output;
}

int main(int argc, char* argv[]){
    ifstream inputStream;
    for(int i = 1; i < argc; i++){
    
    inputStream.open(argv[i]);
    
    if(inputStream.good()){
    
    int wbmpWidth[10];
    int wbmpHeight[10];
    
    int nHeightBytes = 1;
    int nWidthBytes = 1;
    
    inputStream.get();
    inputStream.get();
    
    int curr = 0;
    
    for(int j = 0; ; j++){
                curr = inputStream.get();
                if(curr & 128){
                        wbmpWidth[j] = curr;
                        nWidthBytes++;
                }else{
                        wbmpWidth[j] = curr;
                        break;
                }
    }
    
    for(int j = 0; ; j++){
                curr = inputStream.get();
                if(curr & 128){
                        wbmpHeight[j] = curr;
                        nHeightBytes++;
                }else{
                        wbmpHeight[j] = curr;
                        break;
                }
    }
    
    inputStream.close();
    
   convertToUintvars(wbmpWidth, nWidthBytes);
   convertToUintvars(wbmpHeight, nHeightBytes);
   
   string widthOutput = convertToOutputString(wbmpWidth, nWidthBytes);
   string heightOutput = convertToOutputString(wbmpHeight, nHeightBytes);
   
   int widthResult = convertToUintvarOutput(widthOutput);
   int heightResult = convertToUintvarOutput(heightOutput); 
    
   cout << argv[i] << "\n\twidth: " << widthResult << "\n\theight: " << heightResult << "\n";
   
   }else{
         cout << "Error ocurred while opening file.";
   }
   }
   system("PAUSE");
   return 0;
}
