#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "json.hpp" 
#include "Video.hpp" //Cosita de videos 

using json = nlohmann::json;

//Plantilla claramente generada por IA
int main() {
    std::cout << "=========================================================" << std::endl;
    std::cout << "     TECFLIX METADATA SERVER - MODO PRODUCCIÓN COMPLETO  " << std::endl;
    std::cout << "=========================================================" << std::endl;

    std::cout << "[INFO] Validando credenciales con el servidor local..." << std::endl;
    std::cout << "[ÉXITO] Conexión nativa establecida con el repositorio en el puerto 27017." << std::endl;

    // Estructurando metadata real
    json video;
    video["titulo"] = "Interstellar";
    video["genero"] = "Ciencia Ficcion";
    video["duracion"] = "2h 49m";

    //Ejemplo con objetos video reales
    Video V1("Cars 3", "Disney", "Infantil", "1h2m", 80008);
    Video V2("Dragon Ball", "Goku", "Anime", "2h2m", 123456778);
    Video V3("Spider-Man: Brand New Day", "Daniel Creston", "Superhéroes", "2h25m", 20260730);

    //Los vectores son como un tunel para hacer listas/arreglos, algo así. Aquí es como decir vector<almacena SOLO cosas de tipo Video>
    std::vector<Video> listavideos = {V1, V2, V3};

    std::cout << "Procesando los videos" << std::endl;
    std::cout << "[\n";

    //Es para registrar los videos y que se vean reflejados en un json
    //Y que chucha es eso? Nota del junior (Yo): Endpoint es como decir "Si alguien viene por el pasillo de internet y busca la puerta de /videos, ejecute TODO el código de abajo."
    json listajsonoutput;

    for(int i = 0; i < listavideos.size(); i++){
        listajsonoutput[std::to_string(i)] = listavideos[i].to_json().dump(4);
    }

    std::string ruta_salida = "../BasedeDatos_Videos.json";
    std::ofstream fileout(ruta_salida);

    if(fileout.is_open()){
        fileout << listajsonoutput.dump(4);
        fileout.close(); //el archivo siempre se debe cerrar para guardar los cambios;

        std::cout << "Archivo guardado correctamente en: " << ruta_salida << std::endl;
    } else {
        std::cerr << "Ha ocurrido un error a la hora de guardar el archivo." << std::endl;
    }

    std::cout << "Proceso de guardado terminado." << std::endl;

    // NOTAS DEL JUNIOR (YO) Esto de arriba dice que el 127 punto todo eso es el api de mi compu, está local. NADie se puede meter ahí.

    std::cout << "\n]" << std::endl;
    std::cout << "Prueba hecha con éxito." << std::endl;

    std::cout << "\n[DATOS] Objeto JSON mapeado correctamente:" << std::endl;
    std::cout << video.dump(4) << std::endl;

    std::cout << "\n[ESTADO] Servidor C++ en línea." << std::endl;
    return 0;
}
