#include <string>
#include <iostream>
#include <cstdint>
#include "../include/compiler.hpp"

size_t ptr = 0;
uint8_t memory[30000] = {0};
int hlp = 0;

void execute(std::string code) {
    size_t length = code.size();
    
    for (size_t i = 0; i < length; i++) {
        hlp = 0;
        switch(code[i]) {
            case '>':
                while (i < length && code[i] == '>') { hlp++; i++; }
                i--; ptr = (ptr + hlp) % 30000;
                break;
            case '<':
                while (i < length && code[i] == '<') { hlp++; i++; }
                i--; ptr = (ptr - hlp + 30000) % 30000;
                break;
            case '+':
                while (i < length && code[i] == '+') { hlp++; i++; }
                i--; memory[ptr] += hlp;
                break;
            case '-':
                while (i < length && code[i] == '-') { hlp++; i++; }
                i--; memory[ptr] -= hlp;
                break;
            case '.':
                std::cout << static_cast<char>(memory[ptr]);
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
                if (i + 2 < length && (code[i+1] == '-' || code[i+1] == '+') && code[i+2] == ']') {
                    memory[ptr] = 0;
                    i += 2;
                    break;
                }
                
                if (memory[ptr] == 0) {
                    int counter = 1;
                    while (counter > 0 && ++i < length) {
                        if (code[i] == '[') counter++;
                        else if (code[i] == ']') counter--;
                    }
                }
                break;
            case ']':
                if (memory[ptr] != 0) {
                    int counter = 1;
                    while (counter > 0 && i > 0) {
                        i--;
                        if (code[i] == ']') counter++;
                        else if (code[i] == '[') counter--;
                    }
                }
                break;
            default:
                break;
        }
    }
}
