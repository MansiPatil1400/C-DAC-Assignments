//============================================================================
// Name        : NetworkRequestDispatcherPartA.cpp
// Author      : Mansi Patil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

enum class HttpStatus {
    OK = 200,
    Created = 201,
    BadRequest = 400,
    Unauthorized = 401,
    NotFound = 404,
    ServerError = 500
};

void handleResponse(HttpStatus status, const string& endpoint) {

    cout << "[GET " << endpoint << "] → ";

    switch (status) {

        case HttpStatus::OK:
            cout << "200 OK : Request successful";
            break;

        case HttpStatus::Created:
            cout << "201 Created : Resource created";
            break;

        case HttpStatus::BadRequest:
            cout << "400 Bad Request : Invalid request";
            break;

        case HttpStatus::Unauthorized:
            cout << "401 Unauthorized : Authentication required";
            break;

        case HttpStatus::NotFound:
            cout << "404 Not Found : Endpoint does not exist";
            break;

        case HttpStatus::ServerError:
            cout << "500 Server Error : Internal server error";
            break;
    }

    cout << endl;
}

int main() {

    handleResponse(HttpStatus::OK, "/api/users");

    handleResponse(HttpStatus::Unauthorized, "/api/login");

    handleResponse(HttpStatus::NotFound, "/api/products/99");

    handleResponse(HttpStatus::ServerError, "/api/order");

    return 0;
}
