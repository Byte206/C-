#include <iostream>
#include <fstream>
#include <string>

void replace_string(std::string& content, const std::string& s1, const std::string& s2) {
    if (s1.empty())
        return;
    
    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = content.find(s1, pos)) != std::string::npos) {
        result.append(content, pos, found - pos);
        result.append(s2);
        pos = found + s1.length();
    }
    result.append(content, pos);
    content = result;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return 1;
    }

    std::string content;
    std::string line;
    while (std::getline(inputFile, line)) {
        content += line;
        if (!inputFile.eof())
            content += "\n";
    }
    inputFile.close();

    replace_string(content, s1, s2);

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create output file" << std::endl;
        return 1;
    }

    outputFile << content;
    outputFile.close();

    return 0;
}