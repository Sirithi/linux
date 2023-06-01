#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include <getopt.h>

void print_help() {
    std::cout << "usage: {PROJECT} [-h][-v]\n";
    std::cout << "  -h, --help    show this help text and exit\n";
    std::cout << "  -v, --version show version number and exit\n";
}

void print_version() {
    std::cout << "{PROJECT} version 1.0\n";
}

int main(int argc, const char * argv[]) {
    try {
        struct option long_options[] = {
            {"help", no_argument, nullptr, 'h'},
            {"version", no_argument, nullptr, 'v'},
            {nullptr, 0, nullptr, 0}
        };
        int opt_char, option_index;
        while ((opt_char = getopt_long(argc, const_cast<char* const *>(argv), "hv", long_options, &option_index)) != -1) {
            switch (opt_char) {
                case 0: {
                    // handle long-only options here
                    std::string optname {long_options[option_index].name};
                    break;
                }
                case 'h':
                    print_help();
                    return EXIT_SUCCESS;
                case 'v':
                    print_version();
                    return EXIT_SUCCESS;
                case '?':
                    throw std::runtime_error("unrecognized option");
            }
        }
        if (optind == argc) {
            // here when no file args
        }
        for (int i = optind; i < argc; ++i) {
            try {
                // process file argv[i]
            } catch (const std::runtime_error& ex) {
                std::cerr << "{PROJECT}: " << ex.what() << '\n';
            }
        }
        std::cout << "hello, {PROJECT}\n";
    } catch (const std::exception& ex) {
        std::cerr << "{PROJECT}: " << ex.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
