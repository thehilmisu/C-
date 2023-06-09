
#include <iostream>
#include <sstream>

using namespace std;


string reverseHexDigits(string hexString)
{
  string reversed = "";
  
  for(int i=hexString.length()-2;i>=0;i=i-2)
    reversed.append(hexString.substr(i,2));
 
  return reversed;
}

string hexToASCII(uint64_t data)
{
    ostringstream ss;
    ss << std::hex << data;

    string hex = reverseHexDigits(ss.str());

    // initialize the ASCII code string as empty.
    string ascii = "";
    for (size_t i = 0; i < hex.length(); i += 2)
    {
        // extract two characters from hex string
        string part = hex.substr(i, 2);

        // change it into base 16 and
        // typecast as the character
        char ch = stoul(part, nullptr, 16);

        // add this char to final ASCII string
        ascii += ch;
    }
    return ascii;
}

int main() {

    uint64_t data = 0x6176656e67657273;
    //cout << data << endl;
    //cout << hexToASCII("6176656e67657273") << endl;
    cout << hexToASCII(data) << endl;

    char a  = getchar();

    return 0;
}
