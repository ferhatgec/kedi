#include <iostream>
#include <vector>
#include <tuple>

#include <kedi_main.hpp>

int main() {
    Kedi data;

    data.Read("project.kedi");


    std::vector<std::string> shell = {
            std::get<1>(data.Tree->Extract("USER", "shell")),
            std::get<1>(data.Tree->Extract("USER", "username")),
            std::get<1>(data.Tree->Extract("USER", "path"))
    };

    std::cout
        << "Your shell is       '" << shell[0] << "'\n"
        << "Your username is    '" << shell[1] << "'\n"
        << "Your path is        '" << shell[2] << "'\n";

    return 0;
}
