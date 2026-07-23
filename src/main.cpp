#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "../include/argc.hpp"
#include "../include/compiler.hpp"
#include "../include/transpiler.hpp"

int main(int argc, char* argv[]) {
    ArgsContext args(argc, argv);
    
    if (args.hasArg("run")) {
        auto filename_opt = args.getArg("run");
        if (!filename_opt.has_value()) {
            std::cerr << "Error: Missing input file.\n";
            return 1;
        }

        std::ifstream file((std::string(filename_opt.value())));
        if (!file) {
            std::cerr << "Error: Couldn't open file.\n";
            return 1;
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string file_content = buffer.str();

        execute(file_content);

        file.close();
    } else if (args.hasArg("to")) {
        auto filename_opt = args.getArg("to");
        if (!filename_opt.has_value()) {
            std::cerr << "Error: Missing input file.\n";
            return 1;
        }

        std::ifstream file((std::string(filename_opt.value())));
        if (!file) {
            std::cerr << "Error: Couldn't open file.\n";
            return 1;
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string file_content = buffer.str();

        transpile(std::string(args.getArg(filename_opt.value()).value_or("")), file_content);

        file.close();
    }

    return 0;
}
