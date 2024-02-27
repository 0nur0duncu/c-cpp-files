#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

using Poco::Net::HTTPServer;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;

class MyRequestHandler: public HTTPRequestHandler {
public:
    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response) {
        std::ostringstream oss;
        oss << "Hello, world!\n";
        response.send() << oss.str();
    }
};

class MyRequestHandlerFactory: public HTTPRequestHandlerFactory {
public:
    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest&) {
        return new MyRequestHandler;
    }
};

int main(int argc, char** argv) {
    HTTPServer server(new MyRequestHandlerFactory, 8080);
    server.start();
    std::cout << "Server started on port 8080." << std::endl;
    server.waitForStop();
    return 0;
}
