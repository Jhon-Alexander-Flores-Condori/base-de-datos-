#ifndef CLISTAPRENDA_HPP
#define CLISTAPRENDA_HPP

#include "cPrenda.hpp"

class cListaPrenda
{
    public:
        cListaPrenda();
        cListaPrenda(cPrenda * nuevo, int tam, char *code, char * source);

        bool llenado_codigo(char *code, int size = 0);
        bool llenado_almacen(int value);
        bool llenado_prenda(cPrenda * nuevo, int value);
        bool llenado_material(char *code, int size = 0);
        bool llenado_size_cod(int size, char * cadena = nullptr);
        bool llenado_size_material(int size, char * cadena = nullptr);
        bool llenado_size(int valor);
        bool llenado_precio_total();

        cPrenda * getStorage();
        char* getCodigo();
        char* getMaterial();
        int getSize();
        int getSize_code();
        int getSize_material();
        int getPrecio_total();


        void print();
        void llenado_nullptr();

        bool addContent(cPrenda *nuevo, int add);
        bool deleteContent(int begin, int end);

        void buscarTalla(char * codigo, int * temp);
        void buscarColor(char * codigo, int * temp);
        void buscarFecha(char * codigo,int fin, int inicio, int* temp);
        void buscarNombre(char * codigo,int fin, int inicio, int* temp);

        ~cListaPrenda();

    private:
        cPrenda * manyClothes;
        char * codigo;//MODELO
        char * material;
        float precio_total;

        int size_storage;
        int size_code;
        int size_material;

        void copiar(char *root, char *destino, int tam);
        int contador(const char * cadena);

        void crear_memoria_arrays(int tam, char **destino);
        void liberar_arrays(char **target);
        void crear_memoria(int, cPrenda **target);
        void liberar_memoria(cPrenda **target);
};


#endif
