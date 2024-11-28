#ifndef CPATTERN_HPP
#define CPATTERN_HPP

class cPattern
{
    public:
        cPattern();
        virtual ~cPattern();

    protected:
        virtual void liberar_memoria() const = 0;//para el tipo
        virtual void crear_memoria() const = 0;//para el tipo
        virtual void liberar_arrays(char **target) const = 0;//para los arrays
        virtual void crear_memoria_arrays(int tam, char **destino) const = 0;
        virtual void copiar(char *root, char *destino, int tam) const = 0;
        virtual int contador(const char * cadena) const = 0;
};

#endif
