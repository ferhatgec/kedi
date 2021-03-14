#include <iostream>
#include <tuple>

#include <kedi_main.hpp>

int main() {
    Kedi data;

    std::string str_data = "[author\n"
                       "    =name 'Ferhat'\n"
                       "    =surname 'Gecdogan'\n"
                       "    =gender 'male'\n"
                       "]";

    data.ReadStr(str_data);

    auto name    = std::get<1>(data.Tree->Extract("author", "name"));
    auto surname = std::get<1>(data.Tree->Extract("author", "surname"));

    std::cout << "Author infos\n"
        << " Name:    " << name << '\n'
        << " Surname: " << surname << '\n';

    return 0;
}
