//
//  server.cpp
//  TP C++
//  Eric Lecolinet - Telecom ParisTech - 2016.
//

#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "server.h"
#include "tcpserver.h"

const int PORT = 3331;


int serverStart(Database *database){
  auto *server = new TCPServer([&](string const &request, string &response){
            return database->processRequest(request, response);
        });
    // lance la boucle infinie du serveur
  std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    //en cas d'erreur
    if (status<0) {
    std::cerr << "Could not start Server on port " << PORT << std::endl;
    return 1;      
    }

    return 0;
}
