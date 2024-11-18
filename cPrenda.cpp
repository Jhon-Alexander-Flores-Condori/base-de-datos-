#include "cPrenda.hpp"
#include "cFecha.hpp"

#include <iostream>
#include <ctime>

cPrenda::cPrenda()
{
    asignar_nullptr();
	fecha.actualizarFecha();

    precio_unitario = -1.0;
	peso = -1.0;

    size_color = -1;
    size_talla = -1;
    size_medida = -1;
}

cPrenda::cPrenda(char * name, char *code, char * measure, int tam_cod, int tam_name,
				 int tam_measure,float money)
{
    asignar_nullptr();
	fecha.actualizarFecha();

	if(llenado_talla(code, tam_cod))
	{
		std::cout<<"TALLA LLENADO CON EXITO"<<std::endl;
	}
	else
	{
		std::cout<<"TALLA no LLENO"<<std::endl;
	}

	if(llenado_color(name, tam_name))
	{
		std::cout<<"COLOR LLENADO CON EXITO"<<std::endl;
	}
	else
	{	std::cout<<"COLOR no LLENO"<<std::endl;
	}

	if(llenado_medida(measure, tam_measure))
	{
		std::cout<<"PESO LLENADO CON EXITO"<<std::endl;
	}
	else
	{
		std::cout<<"PESO no LLENO"<<std::endl;
	}

	if(llenado_precio_unitario(money))
	{
		std::cout<<"PRECIO LLENADO CON EXITO"<<std::endl;
	}
	else
	{
		std::cout<<"PRECIO no LLENO"<<std::endl;
	}

}

cPrenda::cPrenda(const cPrenda &obj) // Constructor de copia
{
	asignar_nullptr();

	if(asignarValores(&obj)) {
		std::cout << "SE LOGRO" << std::endl;
	} else {
		std::cout << "NO SE LOGRO" << std::endl;
	}

	std::cout << "CONSTRUCTOR DE COPIA" << std::endl;
}

cPrenda& cPrenda::operator=(const cPrenda &obj) // Operador de asignación
{
	if(&obj != this) {
		if(asignarValores(&obj)) {  // Pasamos la dirección de `obj` para cumplir con el tipo
			std::cout << "SE LOGRO" << std::endl;
		} else {
			std::cout << "NO SE LOGRO" << std::endl;
		}
	} else {
		std::cout << "NO SE LOGRO - no copia de si mismo" << std::endl;
	}

	std::cout << "SOBRECARGA DE OPERADOR" << std::endl;
	return *this;//devolver la referencia
}

bool cPrenda::asignarValores(const cPrenda *obj)
{

	bool flag = true;
	fecha = (*obj).fecha;
	fecha.actualizarFecha();

	if(llenado_talla((*obj).talla, (*obj).size_talla))
	{
		std::cout<<"TALLA LLENADO CON EXITO"<<std::endl;
	}
	else
	{
		std::cout<<"TALLA no LLENO"<<std::endl;
		flag = false;
	}

	if(llenado_color((*obj).color, (*obj).size_color))
	{
		std::cout<<"COLOR LLENADO CON EXITO"<<std::endl;
	}
	else
	{	std::cout<<"COLOR no LLENO"<<std::endl;
		flag = false;
	}

	if(llenado_medida((*obj).unidad_medida, (*obj).size_medida))
	{
		std::cout<<"PESO LLENADO CON EXITO"<<std::endl;
	}
	else
	{
		std::cout<<"PESO no LLENO"<<std::endl;
		flag = false;
	}

	if(llenado_precio_unitario((*obj).precio_unitario))
	{
		std::cout<<"PRECIO LLENADO CON EXITO"<<std::endl;
	}
	else
	{
		std::cout<<"PRECIO no LLENO"<<std::endl;
		flag= false;
	}

	if(llenado_peso((*obj).peso))
	{
		std::cout<<"PESO LLENADO CON EXITO"<<std::endl;
	}
	else
	{
		std::cout<<"PESO no LLENO"<<std::endl;
		flag= false;
	}

	return flag;

}

void cPrenda::print()
{
	char respuesta {'N'};
	bool valido = true;

	if (color != nullptr)
	{
		std::cout<<"COLOR: " <<color<<" tam:"<<size_color<<std::endl;
	}
	else
	{
		std::cout << "Color no asignado (nullptr)" << std::endl;
		valido = false;
	}

	if (talla!= nullptr)
	{
    std::cout<<"TALLA: " <<talla<<" tam:"<<size_talla<<std::endl;
	}
	else
	{
		std::cout << "Talla no asignado (nullptr)" << std::endl;
		valido = false;
	}


}


void cPrenda:: asignar_nullptr()
{
    color = nullptr;
    talla = nullptr;
    unidad_medida = nullptr;
	cadena_fecha = nullptr;
}

void cPrenda::llenado_generalFecha()
{
	char respuesta;

	std::cout<<"Desea inicializar fecha o por defecto? (Y/N): ";
	std::cin>>respuesta;

	if(respuesta == 'Y' || respuesta == 'y')
	{
		llenado_fecha();
	}
	else
	{	fecha.actualizarFecha();	}

}

void cPrenda::llenado_fecha()
{
	int valor =0;

	std::cout<<"dia: ";
	std::cin>> valor;
	fecha.setDia(valor);
	std::cout<<" "<<std::endl;

	std::cout<<"mes: ";
	std::cin>> valor;
	fecha.setMes(valor);
	std::cout<<" "<<std::endl;

	std::cout<<"year: ";
	std::cin>> valor;
	fecha.setYear(valor);
	std::cout<<" "<<std::endl;

	std::cout<<"Segundo: ";
	std::cin>> valor;
	fecha.setSeg(valor);
	std::cout<<" "<<std::endl;

	std::cout<<"Minuto: ";
	std::cin>> valor;
	fecha.setMin(valor);
	std::cout<<" "<<std::endl;

	std::cout<<"Hora: ";
	std::cin>> valor;
	fecha.setHora(valor);
	std::cout<<" "<<std::endl;
}

bool cPrenda::llenado_precio_unitario(float numero)
{
	if(numero<=0.0)
	{
		precio_unitario = -1.0;
		return false;
	}
	precio_unitario = numero;
	return true;
}

bool cPrenda::llenado_peso(float numero)
{
	if(numero<=0.0)
	{
		peso = -1.0;
		return false;
	}
	peso = numero;
	return true;
}

bool cPrenda::llenado_medida(char * medida,int size)
{
	fecha.actualizarFecha();

	if(medida != nullptr)
	{
		if(unidad_medida != nullptr)
		{
			liberar(&unidad_medida);
		}
		if(llenado_size_medida(size,medida))
		{
			crear_memoria(size_medida, &unidad_medida);
			copiar(medida, unidad_medida, size_medida);
			return true;
		}
	}

	return false;

}

bool cPrenda::llenado_size_medida(int size, char * cadena)
{
	if(size <= 1)//o por deafult o no lo lleno
	{
		size = contador(cadena);
		if(size<=1) // still 0, no se crea nada
		{
			std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
			return false;
		}
	}

	size_medida = size;
	return true;
}

bool cPrenda::llenado_size_color(int size, char * cadena)
{
	if(size <= 1)//o por deafult o no lo lleno
	{
		size = contador(cadena);
		if(size<=1)// still 0, no se crea nada
		{
			std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
			return false;
		}
	}

	size_color = size;
	return true;
}

bool cPrenda::llenado_size_talla(int size, char * cadena)
{
	if(size <= 1)//o por deafult o no lo lleno
	{
		size = contador(cadena);
		if(size<=1) // still 0, no se crea nada
		{
			std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
			return false;
		}
	}

	size_talla = size;
	return true;
}

bool cPrenda::llenado_color(char *name, int size)
{
	fecha.actualizarFecha();

	if(name != nullptr)//existe, puedes copiar
	{
		//si nombre esta ocupado
		if(color != nullptr) //liberar memoria de nombre
			{  liberar(&color); }

		if(llenado_size_color(size, name))
		{
			crear_memoria(size_color, &color);
			copiar(name, color, size_color);
			return true;
		}
	}
	std::cout<< "ERROR AL LLENAR COLOR" <<std::endl;
	return false;
}
//code lo que te mandan
bool cPrenda::llenado_talla(char *code, int size)
{
	fecha.actualizarFecha();
	if(code != nullptr)//existe, puedes copiar
	{
		//si nombre esta ocupado
		if(talla != nullptr) //liberar memoria de nombre
			{  liberar(&talla); }

		if(llenado_size_talla(size, code))
		{
			crear_memoria(size_talla, &talla);
			copiar(code, talla, size_talla);
			return true;
		}
	}
	std::cout<< "ERROR AL LLENAR TALLA" <<std::endl;
	return false;

}

char * cPrenda::getColor()
{
	return color;
}

char * cPrenda::getTalla()
{
	return talla;
}

char * cPrenda::getFecha()
{
    if(cadena_fecha != nullptr)
    {
       liberar(&cadena_fecha);
    }
    crear_memoria(8,&cadena_fecha);

    cadena_fecha[0] = fecha.getDia();
    cadena_fecha[1] = fecha.getMes();
    cadena_fecha[2] = fecha.getYear() / 100;
    cadena_fecha[3] = fecha.getYear() % 100;
    cadena_fecha[4] = fecha.getSeg();
    cadena_fecha[5] = fecha.getMin();
    cadena_fecha[6] = fecha.getHora();
    cadena_fecha[7] = '\0';

    return cadena_fecha;
}

char  *cPrenda::getMedida()
{
	return unidad_medida;
}
float cPrenda::getPrecio_unitario()
{
	return precio_unitario;
}

float cPrenda::getPeso()
{
	return peso;
}

int cPrenda::getSize_color()
{
	return size_color;
}

int cPrenda::getSize_talla()
{
	return size_talla;
}

int cPrenda::getSize_medida()
{
	return size_medida;
}


int cPrenda::contador(const char * cadena)
{
	int fin =0;
	while( *(cadena+fin) != '\0')
	{
		fin++;
	}
	return fin+1;
}

void cPrenda::crear_memoria(int tam, char ** destino)
{
	if (tam > 0) 	//nombre
	{	*destino = new char[tam]; }
	else
	{
		*destino = nullptr;
		std::cout<<"array = 0 bytes?"<< std::endl;
	}
}

void cPrenda::copiar( char *root, char *destino, int tam)
{
	for(int i=0;i<tam;i++)
	{
		*(destino+i) = *(root+i);
	}
	*(destino+(tam-1)) = '\0';//asegurar
}

void cPrenda::liberar(char **target)
{
	if (*target != nullptr) {
        delete[] *target; // Libera la memoria asignada a nombre
        *target = nullptr; // Opcional: poner el puntero a nullptr para evitar accesos futuros
    }
}




cPrenda::~cPrenda()
{
    fecha.actualizarFecha();
	liberar(&unidad_medida);
	liberar(&talla);
	liberar(&cadena_fecha);
	liberar(&color);
}





