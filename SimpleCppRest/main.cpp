#include <iostream>
#include <string>
using namespace std;

//#include <nlohmann/json.hpp>

//using json1 = nlohmann::json;

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>


using namespace web::http;
using namespace web::http::client;
using namespace Concurrency::streams;
//using namespace web::json;


int main() {

    http_client client(U("http://first.test/api/assets"));

    http_response response = client.request(methods::GET).get();

    auto body = response.extract_string().get();

    cout<<body;

//    auto my/**/

//    cout << response.extract_json();
//
//    if(response.status_code() == status_codes::OK) {
////        json1 output = response.extra
//
//        for(json1::iterator it =  output.begin(); it != output.end(); ++it){
//            std::cout << it.key() << " : " << it.value() << "\n";
//        }
//
//
//
//    }


    return 0;
}