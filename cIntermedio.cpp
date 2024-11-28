#include "cPattern.hpp"
#include <iostream>


void cIntermedio::liberar_arrays(char **target)
{
    if (*target != nullptr)
    {
        delete[] *target; // Libera la memoria asignada a nombre
        *target = nullptr; // Opcional: poner el puntero a nullptr para evitar accesos futuros
    }
    else
    {
        std::cout<<"Already empty!"<<std::endl;
    }
}

void cIntermedio::crear_memoria_arrays(int tam, char **destino)
{
    if(*destino != nullptr)
    {
        liberar_arrays(destino);
    }

    if (tam > 0) 	//nombre
	{	*destino = new char[tam]; }
	else
	{
		*destino = nullptr;
		std::cout<<"array = 0 bytes?"<< std::endl;
	}
}

void cIntermedio::copiar(char *root, char *destino, int tam)
{
    for(int i=0;i<tam;i++)
	{
		*(destino+i) = *(root+i);
	}
	*(destino+(tam-1)) = '\0';//asegurar
}

int cIntermedio::contador(const char * cadena)
{
	int fin =0;

	while( *(cadena+fin) != '\0')
	{
		fin++;
	}
	return fin+1;
}
