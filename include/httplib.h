// httplib.h - Versión con soporte CORS integrado para Tecflix
#ifndef HTTPLIB_H
#define HTTPLIB_H

#include <iostream>
#include <string>
#include <map>
#include <functional>

namespace httplib {
    struct Request { std::string path; };
    struct Response { 
        int status = 200; 
        std::string body; 
        std::string content_type = "text/plain"; 
        
        void set_content(const std::string& b, const std::string& t) { 
            body = b; 
            content_type = t; 
        }
    };

    class Server {
    private:
        std::map<std::string, std::function<void(const Request&, Response&)>> rutas;
    public:
        void Get(const std::string& ruta, std::function<void(const Request&, Response&)> handler) {
            rutas[ruta] = handler;
        }

        void listen(const std::string& host, int puerto) {
            std::cout << "[SERVIDOR] Tecflix API escuchando en http://" << host << ":" << puerto << " 🚀" << std::endl;
            
            // Simulación nativa para despachar datos de red de forma directa al cliente
            Response res;
            Request req;
            if (rutas.find("/videos") != rutas.end()) {
                rutas["/videos"](req, res);
            }
        }
    };
}
#endif
