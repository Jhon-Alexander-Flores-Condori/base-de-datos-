#ifndef CLISTAALMACEN_HPP
#define CLISTAALMACEN_HPP

#include "cAlmacen.hpp"

class cListaAlmacen
{
    public:
        cListaAlmacen();
        cListaAlmacen(cAlmacen * nuevo, int tam, char *code, int tam_cod);

        bool llenado_codigo(char *code, int size = 0);
        bool llenado_size_cod(int size, char * cadena = nullptr);
        bool llenado_size(int valor);
        bool llenado_almacen(cAlmacen *nuevo, int value);

        cAlmacen * getStorage();
        char* getCodigo();
        int getSize();
        int getSize_code();

        void print();

        bool addContent(cAlmacen *nuevo, int add);
        bool deleteContent(int begin, int end);

        void buscarCodigo(char * codigo, int * temp);
        void buscarFecha(char * codigo,int fin, int inicio, int* temp);
        void buscarNombre(char * codigo,int fin, int inicio, int* temp);

        ~cListaAlmacen();

    private:
        cAlmacen *manyStorages;
        char * codigo;

        int size_storage;
        int size_code;

        void llenado_nullptr();
        void copiar(char *root, char *destino, int tam);
        int contador(const char * cadena);

        void crear_memoria_arrays(int tam, char **destino);
        void liberar_arrays(char **target);
        void crear_memoria(int, cAlmacen **target);
        void liberar_memoria(cAlmacen **target);
};


#endif
