#include <iostream>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

using namespace std;

int main() {
    json j;
    j["pi"] = 3.142;
    j["happy"] = true;
    j["name"] = "Niels";
    j["nothing"] = nullptr;
    j["answer"]["everything"] = 42;
    j["list"] = {1, 0, 2};
    j["object"] = {{"currency", "USD"},
                   {"value",    42.99}};

    json j2 = {
            {"pi",      3.141},
            {"happy",   true},
            {"name",    "Niels"},
            {"nothing", nullptr},
            {"answer",  {
                                {"everything", 42}
                        }},
            {"list",    {       1, 0, 2}},
            {"object",  {
                                {"currency",   "USD"},
                                   {"value", 42.99}
                        }}
    };


    for(json::iterator it = j2.begin(); it != j2.end(); ++it) {
        std::cout << it.key() << " : " << it.value() << '\n';
    }



    return 0;
}