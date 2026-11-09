// json.hpp - Versión final calibrada sin ambigüedades para Windows y MSVC
#ifndef INCLUDE_JSON_HPP_
#define INCLUDE_JSON_HPP_

#include <iostream>
#include <map>
#include <string>

namespace nlohmann {
    class json {
    private:
        // Almacenamos internamente las claves y valores como texto
        std::map<std::string, std::string> datos;
    public:
        // ÚNICO OPERADOR DE CORCHETES: Recibe un string por valor. 
        // Esto elimina cualquier conflicto con los textos "entre comillas" directos.
        std::string& operator[](std::string clave) {
            return datos[clave];
        }

        // Permite la asignación directa de objetos json
        void operator=(const json& otro) {
            this->datos = otro.datos;
        }

        // Construye el texto ordenado en formato JSON
        std::string dump(int sangria) {
            std::string resultado = "{\n";
            for (auto const& [clave, valor] : datos) {
                // Si el valor ya viene empaquetado como sub-objeto (empieza con {), no le ponemos comillas extra
                if (!valor.empty() && valor.front() == '{') {
                    resultado += "    \"" + clave + "\": " + valor + ",\n";
                } else {
                    resultado += "    \"" + clave + "\": \"" + valor + "\",\n";
                }
            }
            if (!datos.empty()) {
                resultado.pop_back(); // Elimina la última coma
                resultado.pop_back(); // Elimina el salto de línea
            }
            resultado += "\n}";
            return resultado;
        }
    };
}
#endif
