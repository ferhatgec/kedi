#include <iostream>
#include <tuple>

#include <kedi_main.hpp>

int main() {
    Kedi data;

    data.Read("project.kedi");

    auto x = data.Tree->Extract("project", "language");

    std::cout << "This project written in " << std::get<1>(x) << "\n";

    return 0;
}
