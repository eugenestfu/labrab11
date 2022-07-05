#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

std::ofstream write;
std::ifstream read;

const char ch[] = "-----------------";

void TwoDigitOut(const char* file) {

	read.open(file);
	if (!read) throw std::string("\ncant open\n");
	std::string line;
	std::string nline;
	while (!read.eof()) {
		getline(read, line);
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == ' ') {
				if (nline.size() == 2 && isdigit(nline[0]) && isdigit(nline[1])) {
					std::cout << nline << "\n";
				}
				nline = "";
			}
			else {
				nline += line[i];
			}
		}
	}
	if (nline.size() == 2 && isdigit(nline[0]) && isdigit(nline[1])) {
		std::cout << nline << "\n";
	}

	read.close();
}

void number2() {
	std::vector<int> rands;
	std::vector<std::string> words;
	std::string line;
	std::string nline;
	srand(time(0));
	read.open("n2.txt");
	if (!read) throw std::string("\ncant open\n");
	while (!read.eof()) {
		getline(read, line);
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == ' ') {
				rands.push_back(rand() % 1000);
				words.push_back(nline);
				nline = "";
			}
			else {
				nline += line[i];
			}
		}
	}
	rands.push_back(rand() % 1000);
	words.push_back(nline);
	read.close();
	write.open("coded.txt");
	std::cout << "| key |  word  |\n";
	for (int i = 0; i < rands.size(); i++) {
		write << rands[i] << "\n";
		std::cout << "|" << std::setw(5) << rands[i] << "|" << std::setw(8) << words[i] << "|\n";
	}
	write.close();

	std::cout << "\namount of words: " << rands.size() << "\n";

	read.open("coded.txt");
	if (!read) throw std::string("\ncant open\n");
	std::cout << "\nprotocol:\n";
	std::string saver;
	while (!read.eof()) {
		getline(read, saver);
		if (saver == "") break;
		for (int i = 0; i < rands.size(); i++) {
			if (rands[i] == std::stoi(saver)) {
				std::cout << words[i] << " ";
			}
		}
	}
	std::cout << "\n";
	read.close();
}

int main() {
	try {
		std::cout << ch << "\n" << "\tn1\n";
		TwoDigitOut("text.txt");
		std::cout << ch << "\n" << "\tn2\n";
		number2();
	}
	catch (std::string& e) {
		std::cerr << e << "u gay";
	}
}