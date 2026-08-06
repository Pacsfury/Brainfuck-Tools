#include <iostream>
#include <fstream>
#include <string>
#include "../include/transpiler.hpp"

void transpile(std::string language, std::string code) {

    if (language == "cpp") {
        std::ofstream outputFile("result.cpp");

        if (!outputFile.is_open()) {
            std::cerr << "Error: Could not open the file!" << std::endl;
            return;
        }

        outputFile << "#include <iostream>\n";
        outputFile << "#include <cstdint>\n\n";
        outputFile << "int main() {\n";
        outputFile << "    size_t ptr = 0;\n";
        outputFile << "    uint8_t memory[30000] = {0};\n";

        int hlp = 0;
        for (size_t i = 0; i < code.size(); i++) {
            hlp = 0;
            switch(code[i]) {
                case '>':
                    while (i < code.size() && code[i] == '>') {
                        hlp++;
                        i++;
                    }
                    i--;
                    outputFile << "    ptr += " << hlp << ";\n";
                    break;
                case '<':
                    while (i < code.size() && code[i] == '<') {
                        hlp++;
                        i++;
                    }
                    i--;
                    outputFile << "    ptr -= " << hlp << ";\n";
                    break;
                case '+':
                    while (i < code.size() && code[i] == '+') {
                        hlp++;
                        i++;
                    }
                    i--;
                    outputFile << "    memory[ptr] += " << hlp << ";\n";
                    break;
                case '-':
                    while (i < code.size() && code[i] == '-') {
                        hlp++;
                        i++;
                    }
                    i--;
                    outputFile << "    memory[ptr] -= " << hlp << ";\n";
                    break;
                case '.':
                    outputFile << "    std::cout << static_cast<char>(memory[ptr]);\n";
                    break;
                case ',':
                    outputFile << "    {\n";
                    outputFile << "        char input;\n";
                    outputFile << "        if (std::cin.get(input)) {\n";
                    outputFile << "            memory[ptr] = static_cast<uint8_t>(input);\n";
                    outputFile << "        } else {\n";
                    outputFile << "            memory[ptr] = 0;\n";
                    outputFile << "        }\n";
                    outputFile << "    }\n";
                    break;
                case '[':
                    if (code[++i] == '-' && code[++i] == ']') {
                        outputFile << "memory[ptr] = 0";
                    } else {
                        outputFile << "    while (memory[ptr]) {\n";
                    }
                    break;
                case ']':
                    outputFile << "    }\n";
                    break;
                default:
                    break;
            }
        }
        
        outputFile << "    return 0;\n";
        outputFile << "}\n";
        outputFile.close();
    } else if (language == "python") {
        std::ofstream outputFile("result.py");

        if (!outputFile.is_open()) {
            std::cerr << "Error: Could not open the file!" << std::endl;
            return;
        }

        outputFile << "import sys\n\n";
        outputFile << "memory = [0] * 30000\n";
        outputFile << "ptr = 0\n\n";

        int hlp = 0;
        int indent_level = 0;

        auto write_indent = [&outputFile](int level) {
            for (int j = 0; j < level; j++) outputFile << "    ";
        };

        for (size_t i = 0; i < code.size(); i++) {
            hlp = 0;
            switch(code[i]) {
                case '>':
                    while (i < code.size() && code[i] == '>') { hlp++; i++; }
                    i--;
                    write_indent(indent_level);
                    outputFile << "ptr += " << hlp << "\n";
                    break;
                case '<':
                    while (i < code.size() && code[i] == '<') { hlp++; i++; }
                    i--;
                    write_indent(indent_level);
                    outputFile << "ptr -= " << hlp << "\n";
                    break;
                case '+':
                    while (i < code.size() && code[i] == '+') { hlp++; i++; }
                    i--;
                    write_indent(indent_level);
                    outputFile << "memory[ptr] = (memory[ptr] + " << hlp << ") & 255\n";
                    break;
                case '-':
                    while (i < code.size() && code[i] == '-') { hlp++; i++; }
                    i--;
                    write_indent(indent_level);
                    outputFile << "memory[ptr] = (memory[ptr] - " << hlp << ") & 255\n";
                    break;
                case '.':
                    write_indent(indent_level);
                    outputFile << "sys.stdout.write(chr(memory[ptr]))\n";
                    break;
                case ',':
                    write_indent(indent_level);
                    outputFile << "inp = sys.stdin.read(1)\n";
                    write_indent(indent_level);
                    outputFile << "memory[ptr] = ord(inp) if inp else 0\n";
                    break;
                case '[':
                    write_indent(indent_level);
                    if (code[++i] == '-' && code[++i] == ']') {
                        outputFile << "memory[ptr] = 0";
                    } else {
                        outputFile << "while memory[ptr] != 0:\n";
                        indent_level++;
                    }
                    break;
                case ']':
                    indent_level--;
                    if (indent_level < 0) indent_level = 0; 
                    break;
                default:
                    break;
            }
        }
        
        outputFile.close();
    }

}
