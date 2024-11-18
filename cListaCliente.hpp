#ifndef CLISTACLIENTE_HPP
#define CLISTACLIENTE_HPP

#include "cCliente.hpp"

class cListaCliente
{
    public:
        cListaCliente();  // Constructor por defecto
        cListaCliente(cCliente* nuevo, int tam, char* code, int tam_cod); // Constructor con parámetros
        cListaCliente(const cListaCliente& otra); // Constructor por copia
        cListaCliente& operator=(const cListaCliente& otra); // Operador de asignación

        ~cListaCliente(); // Destructor

        bool llenado_codigo(char* code, int size = 0);
        bool llenado_size_cod(int size, char* cadena = nullptr);
        bool llenado_size(int valor);
        bool llenado_cliente(cCliente* nuevo, int value);

        cCliente* getCliente();
        char* getCodigo();
        int getSize();
        int getSize_code();

        void print();

        bool addContent(cCliente* nuevo, int add);
        bool deleteContent(int begin, int end);

        void buscarCodigo(char* codigo, int* temp);
        void buscarNombre(char* codigo, int fin, int inicio, int* temp);

    private:
        cCliente* manyClients;
        char* codigo;

        int size_cliente;
        int size_code;

        void llenado_nullptr();
        void copiar(const char* root, char* destino, int tam);
        int contador(const char* cadena);

        void crear_memoria_arrays(int tam, char** destino);
        void liberar_arrays(char** target);
        void crear_memoria(int tam, cCliente** target);
        void liberar_memoria(cCliente** target);
};

#endif
