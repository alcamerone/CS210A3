#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int convertToRealValue(int charValue){
       if(charValue - 97 < 0){
                    charValue = charValue - 48;
                    return charValue;
       }else{
             charValue = charValue -87;
             return charValue;
       }
}

void convertToByteNumbers(int inputArray[], int outputArray[], int numOfValues){
    int curr = 0;
    for(int i = 0; i < numOfValues; i = i + 2){
            outputArray[curr] = (inputArray[i] << 4) + inputArray[i+1];
            curr = curr + 1;
    }
    return;
}

void clearErroneousInputs(int inputArray[], int numOfValues, int from){
     for(int i = from + 1; i < numOfValues; i++){
             inputArray[i] = -1;
     }
     return;
}

void convertToUnitvars(int inputArray[], int numOfValues){
     int erroneousAfter = 0;
     for(int i = 0; i < numOfValues; i++){
             if(inputArray[i] & 128){
                              erroneousAfter = i;
                              inputArray[i] = inputArray[i] & 127;
             }else{
                              erroneousAfter = i;
                              inputArray[i] = inputArray[i] & 127;
                              break;
             }
     }
     clearErroneousInputs(inputArray, numOfValues, erroneousAfter);
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

int convertToUnitvarOutput(string outputString){
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
    for(int i = 1; i < argc; i++){             
             string inputString = argv[i];
             int inputs[inputString.size()];
             int numOfInputs = inputString.size();
             for(int j = 0; j < numOfInputs; j++){
                     inputs[j] = inputString[j];
                     inputs[j] = convertToRealValue(inputs[j]);
             }
             int numOfUnitvars = numOfInputs/2;
             int unitvars[numOfUnitvars];
             convertToByteNumbers(inputs, unitvars, numOfInputs);
    
             convertToUnitvars(unitvars, numOfUnitvars);
    
             string outputString = convertToOutputString(unitvars, numOfUnitvars);
    
             int result = convertToUnitvarOutput(outputString);
             
             cout << argv[i];
             cout << ": ";
             cout << result;
             cout << "\n";
    }
    
    system("PAUSE");
    return 0;
}
