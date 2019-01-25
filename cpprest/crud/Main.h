#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>
#include <sstream>
#include <iostream>
#include "cpprest/containerstream.h"
#include "cpprest/producerconsumerstream.h"

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;
using namespace web::json;


#include <iostream>

using namespace std;

#ifndef CRUD_MAIN_H
#define CRUD_MAIN_H



class Main {
public:
    pplx::task<void> getMethod() {
        return pplx::create_task([]{
            http_client client(U("http://first.test/api/test"));

            return client.request(methods::GET);
        }).then([](http_response response) {
            std::wostringstream stream;
            stream << L"Server returned status code " << response.status_code() << L'.' << std::endl;
            std::wcout << stream.str();
            if(response.status_code() == status_codes::OK) {
                return response.extract_json();
            }
            return pplx::create_task([] {
                return json::value();
            });
        }).then([](json::value jsonValue){
            if(jsonValue.is_null())
                return;
        });

    }

    pplx::task<void> getAsync() {
        http_client client(U("http://first.test/api/test"));

        return client.request(methods::GET).then([](http_response response){
            // Display the status code that the server returned
            std::wostringstream stream;
            stream << L"Server returned status code " << response.status_code() << L'.' << std::endl;
            std::wcout << stream.str();

            stream.str(std::wstring());
            stream << L"Content length: " << response.headers().content_length() << L"bytes" << std::endl;
            std::wcout <<stream.str();

            auto bodyStream = response.body();
            Concurrency::streams::stringstreambuf sbuffer;
            auto& target = sbuffer.collection();

            bodyStream.read_to_end(sbuffer).get();

            stream.str(std::wstring());
            stream << L"Stream body: " << target.c_str();
            std::wcout << stream.str();


        });
    }

private:
    void displayJson(json::value v) {
        if(!v.is_null()) {
            // Loop over each element in the object
            for (const auto &iter : v.as_object()) {
                string_t key = iter.first;
                string_t value = iter.second;

            }
        }
    }

};

#endif //CRUD_MAIN_H
