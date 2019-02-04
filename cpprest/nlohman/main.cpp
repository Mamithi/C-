#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main()
{
    // create JSON values
    json j_object = {{"one", 1}, {"two", 2}};
    json j_array = {1, 2, 4, 8, 16};
    json j_string = "Hellö 😀!";

    // call dump()
    std::cout << "objects:" << '\n'
              << j_object.dump() << "\n\n"
              << j_object.dump(-1) << "\n\n"
              << j_object.dump(0) << "\n\n"
              << j_object.dump(4) << "\n\n";

    std::cout << "arrays:" << '\n'
              << j_array.dump() << "\n\n"
              << j_array.dump(-1) << "\n\n"
              << j_array.dump(0) << "\n\n"
              << j_array.dump(4) << "\n\n";

    std::cout << "strings:" << '\n'
              << j_string.dump() << '\n';

    // create JSON value with invalid UTF-8 byte sequence
    json j_invalid = "ä\xA9ü";

}