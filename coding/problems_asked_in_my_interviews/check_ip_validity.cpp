// Taken on Online GDB (https://www.onlinegdb.com/)

// 0 <= xi <= 255
// only numbers allowed
// valid values - (0 - 255)
// no trailing zeros


// conditions for invalid -
// 1. count of dot != 
// 2. if char lies outside 0 - 9
// 3. if int value of char lies outside 0-255 for the segment
// 4. check for trailing zeros
// 5. location of dots

// 192.168.1.00

#include <bits/stdc++.h>
using namespace std;


int computedNumberFromString(string st) {
    return stoi(st);
} 


string isIpAddressValid(string ip) {
    int countOfDots = 0;
    string segment = "";
    
    if (ip[0] == '.' || ip[ip.size()-1] == '.') {
        return "No";
    }
    
    for (int idx = 0; idx < ip.size(); idx++) {
        // 1st condition
        if (ip[idx] == '.') {
            countOfDots++;
            
            if (idx < ip.size()-1 && ip[idx+1] == '.') {
                return "No";
            }
            
            // 3rd condition
            num = computedNumberFromString(segment);
            if (num > 255) {
                return "No";
            }
            
            // 4th condition
            if (num < 1) {
                return "No";
            }
            
            // reset segment
            segment = "";
        }
        
        // 2nd condition
        if (ip[idx] != '.' && int(ip[idx]) < 48 && int(ip[idx]) > 57) {
            return "No";
        }
        
        // 3rd condition
        if (ip[idx] != '.') {
            segment += ip[idx];
        }
        
    }
    
    return "IPv4";
}


int main()
{
    string ip = "192.168.1.1";
    cout << isIpAddressValid(ip);

    return 0;
}

