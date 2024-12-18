/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class CeaserCypher{
  private:
  int shiftvalue;
  protected:
  string encoder(const string& message){
      string result = message;
      int i =0;
      for(char&c :result ){
          const int alphabetSize = 26; 
                  if (isalpha(c)) {

            char base = isupper(c) ? 'A' : 'a';
            int frombase = c - base; 
            int shiftedOffset = (frombase + shiftvalue) % alphabetSize;
            char shifted = base + shiftedOffset;
            result[i]=shifted;
            i++;
      }
  }
  cout<<result;
  return result;

  }
  public:
  int decodeshift;
  void setDecodeshift(int decodeshiftvalue){
      this->decodeshift=decodeshiftvalue;
  }
  void setShiftvalue(int shift){
      this->shiftvalue=shift;
  }
 
    int getShiftvalue(){
      return shiftvalue;
  }
    int getDecodeshift(){
      return decodeshift;
  }
  string encode(const string& message) {
        return encoder(message);
    }
    string decode(const string& message) {
        string decodeattempt = message;
        int i = 0;
        const int alphabetSize = 26;
        for (char& c : decodeattempt) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                int frombase = c - base;
                int shiftedOffset = (frombase + alphabetSize - decodeshift) % alphabetSize;
                char shifted = base + shiftedOffset;
                decodeattempt[i] = shifted;
            }
            i++;
        }
        return decodeattempt;
    }

};
class Rot13:public CeaserCypher{
    public:
    Rot13() {
        setShiftvalue(13);
}
};



int main() {
    CeaserCypher cypher;
    string input = "y";
    string inputd;

    while (input == "y") {
        cout << "Encryptor - Do you want to encode a message? (y or n): ";
        cin >> input;
        cout << endl;

        while (input != "y" && input != "n") {
            cout << "Encryptor - Invalid input. Re-enter (y or n): ";
            cin >> input;
            cout << endl;
        }

        if (input == "y") {
            string message;
            int shift;

            cout << "What would you like encoded: ";
            cin >> message;

            cout << "Enter a number between 1-13: ";
            cin >> shift;

            while (shift < 1 || shift > 13) {
                cout << "Error: Enter a number between 1-13: ";
                cin >> shift;
            }
            
            cypher.setShiftvalue(shift);
            message = cypher.encode(message);
            cout << "Encoded message: " << message << endl;
        }

        cout << "Do you want to decode a message? (y or n): ";
        cin >> inputd;
        
        while (inputd != "y" && inputd != "n") {
            cout << "Invalid input. Re-enter (y or n): ";
            cin >> inputd;
            cout << endl;
        }

        if (inputd == "y") {
            string message;
            int decodeshiftvalue;

            cout << "Enter the message you want to decode: ";
            cin >> message;

            cout << "Enter the decoding shift value (1-13): ";
            cin >> decodeshiftvalue;

            while (decodeshiftvalue < 1 || decodeshiftvalue > 13) {
                cout << "Error: Enter a number between 1-13: ";
                cin >> decodeshiftvalue;
            }

            cypher.setDecodeshift(decodeshiftvalue);
            cout << "Decoded message: " << cypher.decode(message) << endl;
        }

        cout << "Continue? (y or n): ";
        cin >> input;
    }

    cout << "Encoding/Decoding program finished" << endl;
    return 0;
}
