#ifndef CINTERMEDIO_HPP
#define CINTERMEDIO_HPP
#include "cPattern.hpp"

class cIntermedio : public cPattern
{
    public:
        cIntermedio();
        virtual~cIntermedio();
    protected:
        void liberar_memoria() override;//para el tipo
        void crear_memoria() override ;//para el tipo
        void liberar_arrays(char **target) override ;//para los arrays
        void crear_memoria_arrays(int tam, char **destino) override ;
        void copiar(char *root, char *destino, int tam)  override;
        int contador(const char * cadena) override ;
};


#endif
