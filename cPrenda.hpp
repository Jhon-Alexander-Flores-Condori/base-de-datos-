#ifndef CPRENDA_HPP
#define CPRENDA_HPP  

#include "cFecha.hpp"

class cPrenda
{
    public:

        cPrenda();//sin parametros
        cPrenda(char * name, char *code, char * measure, int tam_cod, int tam_name,
				 int tam_mesuare,float money);
        cPrenda(const cPrenda &obj);
        cPrenda& operator=(const cPrenda &obj);
        void print();

        bool llenado_precio_unitario(float numero);
        bool llenado_peso(float numero);
        bool llenado_color(char *name, int size = 0);
		bool llenado_talla(char *code, int size = 0);
        bool llenado_medida(char *medida,int size = 0);
		bool llenado_size_color(int size, char * cadena = nullptr);
        bool llenado_size_medida(int size, char * cadena = nullptr);
		bool llenado_size_talla(int size, char * cadena = nullptr);
		void llenado_fecha();

        char * getFecha();
		char * getColor();
		char * getTalla();
        char * getMedida();
		int getSize_color();
        int getSize_medida();
		int getSize_talla();
        float getPeso();
        float getPrecio_unitario();

        ~cPrenda();

    private:
        cFecha fecha;
        char * talla;
        char * color;
        char * unidad_medida;//peso
        char * cadena_fecha;

        int size_color;
        int size_talla;
        int size_medida;
        float precio_unitario;
        float peso;

        void ultimoAcceso();
		void asignar_nullptr();
		void llenado_generalFecha();

		bool asignarValores(const cPrenda *obj);
		void copiar(char *root, char *destino, int tam);
		int contador(const char *cadena);

        void crear_memoria(int tam, char ** destino);
		void liberar(char **target);
};

#endif
