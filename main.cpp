#include "include/crow_all.h"
#include <iostream>
#include "boost/json.hpp"

int main(void)
{
    crow::SimpleApp app;

    std::cout << "Hello, World!" << std::endl;

    CROW_ROUTE(app, "/")
    ([]()
     { return "Hello, World!"; });

    CROW_ROUTE(app, "/json")
    ([]()
     {
        crow::json::wvalue x({{"message", "Hello, World!"}});
        x["message2"] = "Hello, World... Again!";
        return x; });

    app.port(5400).run();
    return 0;
}
