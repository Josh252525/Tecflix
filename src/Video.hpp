#include "json.hpp"
#include <string>

using json = nlohmann::json;

class Video{

    //Sección de atributos. Es todo lo que tiene un video de la plataforma.
    private: std::string Titulo;
    private: std::string Autor;
    private: std::string Genero;
    private: std::string Duracion;
    private: int ID;

    public: Video(std::string Titulo, std::string Autor, std::string Genero, std::string Duracion, int ID){
        this->Titulo = Titulo;
        this->Autor = Autor;
        this->Duracion = Duracion;
        this->Genero = Genero;
        this->ID = ID;
    }

    public: 
    
    json to_json(){
        json j;
        j["ID"] = std::to_string(ID);
        j["Titulo"] = Titulo;
        j["Duracion"] = Duracion;
        j["Genero"] = Genero;
        j["Autor"] = Autor;
        return j;

    }

};