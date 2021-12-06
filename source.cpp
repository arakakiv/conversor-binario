#include <iostream>
#include <string>
#include <cmath>
#include <vector>

bool isBinary(std::string x);
bool isInt(std::string x);

std::string toBinary(std::string);
std::string toDecimal(std::string);

int main() {
	std::string strOption;
	std::string valueConverted;

	std::string valueToConvert;

	while (strOption != "e") {
		std::cout << "=================================================================================\n\n";

		std::cout << "::: if you wanna convert from decimal number, input 'd'.\n";
		std::cout << "::: if you wanna convert from binary number, input 'b'.\n";
		std::cout << "::: if you wanna exit, input 'e'.\n";

		std::cout << "==> ";
		std::getline(std::cin, strOption);

		if (strOption != "d" && strOption != "b" && strOption != "e") {
			std::cout <<"\n::: I did not understand. Please, try again.\n" << std::endl;
		}
		else if(strOption == "d" || strOption == "b") {
			std::cout << "==> Tell me the value: ";
			std::cin >> valueToConvert;

			if ((strOption == "d" && isInt(valueToConvert)) || (strOption == "b" && isBinary(valueToConvert))) {
				if (strOption == "d") {
					valueConverted = toBinary(valueToConvert);
				}
				else {
					valueConverted = toDecimal(valueToConvert);
				}

				std::cout << "\n::: The value converted is " << valueConverted << std::endl;
				std::cout << std::endl;	
			}
			else {
				std::cout << "\n::: PROBLEM: value and option don't match.\n\n";
			}

			std::cin.ignore();
		}
		else {
			std::cout << "\n::: Bye bye!";
		}
	}
}

bool isBinary(std::string x) {
	int posOfZeroB = x.find("0b");
	int posOfFirstOne = x.find('1');

	for(int i = 0; i < x.length(); ++i) {
		if (x[i] != 'b' && x[i] != '0' && x[i] != '1') {
			return false;
		}
	}

	if (posOfFirstOne < posOfZeroB) {
		return false;
	}

	return true;
}

bool isInt(std::string x) {
	for(int i = 0; i < x.length(); ++i) {
		if (!isdigit(x[i])) {
			return false;
		}
	}

	return true;
}

std::string toBinary(std::string x) {
	std::vector<int> binary;
	std::string returnStr = "0b";

	int aux = std::stoi(x);
	while(aux != 0) {
		binary.push_back(aux % 2);
		aux = aux / 2;
	}

	for (int i = binary.size() - 1; i >=0; --i) {
		returnStr += std::to_string(binary[i]);
	}

	return returnStr;
}

std::string toDecimal(std::string x) {
	int rValue = 0;
	
	for(int i = x.length(); i > 0; --i) {
		if (x[x.length() - i] == '1') {
			rValue +=  pow(2, i - 1);
		}
	}

	return std::to_string(rValue);
}
