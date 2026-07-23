#include <string>
#include <iostream>
#include <cstdint>
#include "../include/compiler.hpp"

size_t ptr = 0;
uint8_t memory[30000] = {0};
int hlp = 0;

void execute(std::string code) {
    for (size_t i = 0;i<code.size();i++) {
        hlp = 0;
        switch(code[i]) {
            case '>':
                while (i < code.size() && code[i] == '>') {
                    hlp++;
                    i++;
                }
                i--;
                ptr += hlp;
                break;
            case '<':
                while (i < code.size() && code[i] == '<') {
                    hlp++;
                    i++;
                }
                i--;
                ptr -= hlp;
                break;
            case '+':
                while (i < code.size() && code[i] == '+') {
                    hlp++;
                    i++;
                }
                i--;
                memory[ptr] += hlp;
                break;
            case '-':
                while (i < code.size() && code[i] == '-') {
                    hlp++;
                    i++;
                }
                i--;
                memory[ptr] -= hlp;
                break;
            case '.':
                std::cout<<static_cast<char>(memory[ptr]);
                break;
            case ',':
                char input;
                if (std::cin.get(input)) {
                    memory[ptr] = static_cast<uint8_t>(input);
                } else {
                    memory[ptr] = 0;
                }
                break;
            case '[':
                break;
            case ']':
                if (memory[ptr] != 0) {
                    int counter = 1; 
                    while (counter > 0) {
                        i--; 
                        if (code[i] == ']') {
                            counter++; 
                        } 
                        else if (code[i] == '[') {
                            counter--; 
                        }
                    }
                }
                break;

            default:
                break;
        }
    }
}