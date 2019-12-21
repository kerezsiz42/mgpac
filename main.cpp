#include <iostream>
#include <sstream>

using std::string;
using std::ostringstream;
using std::cout;
using std::endl;

char hexchar2byte(char ch) {
	if (ch > 47 && ch < 58) ch -= 48;
	if (ch > 96 && ch < 103) ch -= 87;
	return ch;
}

char char2lower(char ch) {
	if (ch > 64 && ch < 91) {
		ch += 32;
	}
	return ch;
}

void conv2hex(string input) {
	char sum {0};
	bool flag {false};
	for (auto i: input) {
		if (!flag) {
			sum = 16 * hexchar2byte(i);
			flag = true;
		} else {
			sum += hexchar2byte(i);
			cout << sum;
			flag = false;
		}
	}
}

int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Please add the MAC address of the device you want to wake up as the only argument. ";
		cout << "If HEX values are devided then with colon or dash characters." << endl;
		return -1;
	}
	
	string macAddress = argv[1];
	ostringstream output;
	ostringstream formattedMAC;
	int i;

	// Formatting the given address
	int length = macAddress.length();
	if (length != 12 && length != 17) {
		cout << "Wrong number of characters entered: possibly wrong format. Sould be: xx:xx:xx:xx:xx:xx" << endl;
		return -1;
	}
	for (auto i: macAddress) {
		if(i != ':' && i != '-') {
			formattedMAC << char2lower(i);
		} 
	}

	// Adding the initial 12 f-s
	for (i = 0; i < 12; i++) {
		output << 'f';
	}

	// Adding formatted MAC address 16 times
	for (i = 0; i < 16; i++) {
		output << formattedMAC.str();
	}

	// Outputting as bytecode
	conv2hex(output.str());
	
	return 0;
}