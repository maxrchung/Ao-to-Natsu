#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void main() {
	float f = 1.00000000000000000000000000000001f;
	for (int i = 0; i < 100; ++i) {
		f++;
	}

	//const auto filePath = R"(X:\osu!\Songs\824592 Mrs GREEN APPLE - Ao to Natsu\Mrs. GREEN APPLE - Ao to Natsu (Haruto).osb)";
	//auto input = std::ifstream(filePath);
	//auto content = std::stringstream();
	//auto line = std::string("");
	//while(std::getline(input, line)) {
	//	if (line.size() > 1 && line[0] == ' ') {
	//		auto delimiter = std::stringstream(line);
	//		auto offsetLine = std::stringstream();
	//		auto token = std::string("");
	//		auto counter = 0;
	//		while (std::getline(delimiter, token, ',')) {
	//			if (token.size() > 0 && (counter == 2 || counter == 3)) {
	//				const auto time = std::stoi(token);
	//				const auto offsetTime = time + 33;
	//				const auto offsetValue = std::to_string(offsetTime);
	//				offsetLine << offsetValue << ',';
	//			}
	//			else {
	//				offsetLine << token << ',';
	//			}
	//			counter++;
	//		}
	//		const auto strippedComma = offsetLine.str().substr(0, offsetLine.str().size() - 1);
	//		content << strippedComma << "\n";
	//	}
	//	else {
	//		content << line << "\n";
	//	}
	//}
	//auto output = std::ofstream("Mrs. GREEN APPLE - Ao to Natsu (Haruto).osb");
	//output << content.str();
}