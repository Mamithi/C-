#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>
#include <sstream>
#include <iostream>
#include "cpprest/containerstream.h"
#include "cpprest/producerconsumerstream.h"

#include <nlohmann/json.hpp>

using json1 = nlohmann::json;


using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;
using namespace web::json;


#include <iostream>
#include <iomanip>


using namespace std;


#ifndef CRUD_MAIN_H
#define CRUD_MAIN_H


class Main {
public:
    pplx::task<void> getMethod() {
        json1 res =  getJson();
        for(json1::iterator it = res.begin(); it != res.end(); ++it) {
                std::wcout << it.key() << it.value()  << endl;
        }
//        displayJson(res);

    }

    json1 getJson() {
        http_client client(U("http://first.test/api/test"));

        http_response response = client.request(methods::GET).get();

        std::wostringstream stream;
        stream << L"Server returned status code " << response.status_code() << L'.' << std::endl;
        std::wcout << stream.str();

        stream.str(std::wstring());
//            stream << L"Content length: " << response.headers().content_length() << L"bytes" << std::endl;
        std::wcout << stream.str();

        auto bodyStream = response.body();
        Concurrency::streams::stringstreambuf sbuffer;
        auto &target = sbuffer.collection();

        bodyStream.read_to_end(sbuffer).get();

        stream.str(std::wstring());
        stream << L"Stream body: " << target.c_str();
        std::wcout << stream.str() << endl;

        json1 jValue = json1::parse(stream.str());


        return jValue;

    }



    json::value jsonResponse() {
        json::value res;
        try {
            http_client client(U("http://first.test/api/test"));

            http_response response = client.request(methods::GET).get();

            std::wcout << response.status_code() << endl;

            auto json_response = response.extract_json();
            if (response.status_code() == status_codes::OK) {
                int res_status = json_response.get()["status"].as_integer();

                if (res_status == 200) {
                    string title = json_response.get()["data"]["Title"].as_string();
                    string subtitle = json_response.get()["data"]["Subtitle"].as_string();
                    string description = json_response.get()["data"]["Description"].as_string();
                    string mainPage = json_response.get()["data"]["MainPage"].as_string();
//                    auto items = json_response.get()["data"]["Items"].as_array();
                    string id = json_response.get()["data"]["Id"].as_string();


                    res["title"] = json::value::string(title);
                    res["subtitle"] = json::value::string(subtitle);
                    res["description"] = json::value::string(description);
                    res["mainPage"] = json::value::string(mainPage);
//                    res["items"] = json::value::string(items);
                    res["id"] = json::value::string(id);

                    return res;


                } else {
                    string error_message = json_response.get()["message"].as_string();
                    res["error_message"] = json::value::string(error_message);
                    return res;
                }
            } else {
                string error_message = json_response.get()["message"].as_string();
                res["error_message"] = json::value::string(error_message);
                return res;
            }
        } catch (exception &ex) {
            res["error_code"] = json::value::string("Error Connection");
            res["error_message"] = json::value::string(ex.what());
            return res;
        }
    }

    pplx::task<void> getAsync() {
        http_client client(U("http://first.test/api/test"));

        return client.request(methods::GET).then([](http_response response) {

            // Display the status code that the server returned
            std::wostringstream stream;
            stream << L"Server returned status code " << response.status_code() << L'.' << std::endl;
            std::wcout << stream.str();

            stream.str(std::wstring());
//            stream << L"Content length: " << response.headers().content_length() << L"bytes" << std::endl;
            std::wcout << stream.str();

            auto bodyStream = response.body();
            Concurrency::streams::stringstreambuf sbuffer;
            auto &target = sbuffer.collection();

            bodyStream.read_to_end(sbuffer).get();

            stream.str(std::wstring());
            stream << L"Stream body: " << target.c_str();
            std::wcout << stream.str() << endl;

            json1 jValue = stream.str();

            std::string s = jValue.dump();

        });
    }


};

#endif //CRUD_MAIN_H
