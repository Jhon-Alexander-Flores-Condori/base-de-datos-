#include "cPeluche.hpp"
#include "cPrenda.hpp"
#include <iostream>

cPeluche::cPeluche() : cPrenda()
{
    cPrenda::fecha.actualizarFecha();
    llenado_nullptr();

    size_unidad_relleno = -1;
    precio_relleno = -1.0;
    precio_final = -1.0;
    peso_relleno = -1.0;
    peso_final = -1.0;
}

cPeluche::cPeluche(char * name, char *code, char * measure, int tam_cod, int tam_name,
                   int tam_measure,float money, char * relleno_unidad,
                   int tam_relleno_unidad, float money_relleno, float
                   money_final, float weight_relleno, float weight_final)
        :cPrenda(name, code, measure, tam_cod, tam_name, tam_measure, money)
{
    cPrenda::fecha.actualizarFecha();
    llenado_nullptr();

    if(llenado_unidad_relleno(relleno_unidad, tam_relleno_unidad))
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }

    if(llenado_peso_relleno(weight_relleno))
    {
        std::cout<<"PESO RELLENO LLENADO CON EXITO"<<std::endl;
        if(llenado_peso_final())
        {
           std::cout<<"PESO FINAL LLENADO CON EXITO"<<std::endl;
        }
        else
        {
            std::cout<<"PESO FINAL NO LLENADO CON EXITO"<<std::endl;
        }
    }
    else
    {
        std::cout<<"PESO RELLENO no LLENO"<<std::endl;
    }

    if(llenado_precio_relleno(money_relleno))
    {
        std::cout<<"PRECIO RELLENO LLENADO CON EXITO"<<std::endl;
        if(llenado_precio_final())
        {
           std::cout<<"PRECIO FINAL LLENADO CON EXITO"<<std::endl;
        }
        else
        {
            std::cout<<"PRECIO FINAL NO LLENADO CON EXITO"<<std::endl;
        }
    }
    else
    {
        std::cout<<"PRECIO RELLENO no LLENO"<<std::endl;
    }

}

cPeluche::cPeluche(const cPeluche &obj) : cPrenda(obj)
{
    llenado_nullptr();

	if(asignar_valores(obj)) {
		std::cout << "SE LOGRO" << std::endl;
	} else {
		std::cout << "NO SE LOGRO" << std::endl;
	}

	std::cout << "CONSTRUCTOR DE COPIA" << std::endl;
}

cPeluche& cPeluche::operator=(const cPeluche &obj)
{
	if(&obj != this) {
        cPrenda::operator=(obj);

		if(asignar_valores(obj)) {  // Pasamos la dirección de `obj` para cumplir con el tipo
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

bool cPeluche::asignar_valores(const cPeluche &obj)
{
    bool flag = true;
	fecha = obj.fecha;
	cPrenda::fecha.actualizarFecha();

    if(llenado_unidad_relleno(obj.unidad_relleno, obj.size_unidad_relleno))
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
        flag = false;
    }

    if(llenado_peso_relleno(obj.peso_relleno))
    {
        std::cout<<"PESO RELLENO LLENADO CON EXITO"<<std::endl;
        if(llenado_peso_final())
        {
           std::cout<<"PESO FINAL LLENADO CON EXITO"<<std::endl;
        }
        else
        {
            std::cout<<"PESO FINAL NO LLENADO CON EXITO"<<std::endl;
        }
    }
    else
    {
        std::cout<<"PESO RELLENO no LLENO"<<std::endl;
    }

    if(llenado_precio_relleno(obj.precio_relleno))
    {
        std::cout<<"PRECIO RELLENO LLENADO CON EXITO"<<std::endl;
        if(llenado_precio_final())
        {
           std::cout<<"PRECIO FINAL LLENADO CON EXITO"<<std::endl;
        }
        else
        {
            std::cout<<"PRECIO FINAL NO LLENADO CON EXITO"<<std::endl;
        }
    }
    else
    {
        std::cout<<"PRECIO RELLENO no LLENO"<<std::endl;
    }

    return flag;
}

void cPeluche::llenado_nullptr()
{
    unidad_relleno = nullptr;
}

bool cPeluche::llenado_unidad_relleno(char * cadena, int size)
{
    cPrenda::fecha.actualizarFecha();
    if(cadena != nullptr)
    {
        if(unidad_relleno != nullptr)
        {   cPrenda::liberar(&unidad_relleno);  }

        if(llenado_size_unidad_relleno(size,cadena))
        {
            cPrenda::crear_memoria(size_unidad_relleno, &unidad_relleno);
            cPrenda::copiar(cadena, unidad_relleno, size_unidad_relleno);
            return true;
        }
        else
        {   return false;   }
    }
    return false;
}

bool cPeluche::llenado_size_unidad_relleno(int size,char * cadena)
{
    cPrenda::fecha.actualizarFecha();
    if(size <= 1)//o por deafult o no lo lleno
    {
        size = cPrenda::contador(cadena);
        if(size<=1) // still 0, no se crea nada
        {
            size_unidad_relleno = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
            return false;
        }
    }

    size_unidad_relleno = size;
    return true;
}


bool cPeluche::llenado_peso_relleno(float numero)
{
	cPrenda::fecha.actualizarFecha();
    if(numero<=0.0)
	{
		peso_relleno = -1.0;
		return false;
	}
	peso_relleno = numero;
	return true;
}

bool cPeluche::llenado_precio_relleno(float numero)
{
	cPrenda::fecha.actualizarFecha();
    if(numero<=0.0)
	{
		precio_relleno = -1.0;
		return false;
	}
	precio_relleno = numero;
	return true;
}

bool cPeluche::llenado_peso_final()
{
    cPrenda::fecha.actualizarFecha();
    float valor = cPrenda::getPeso();

    if(valor<=0.0)
	{
		std::cout<<"Peso unitario cprenda invalido"<<std::endl;
        return false;
	}
	peso_final +=valor;
	return true;
}


bool cPeluche::llenado_precio_final()
{
    cPrenda::fecha.actualizarFecha();
    float valor = cPrenda::getPrecio_unitario();

    if(valor<=0.0)
	{
		std::cout<<"Precio unitario cprenda invalido"<<std::endl;
        return false;
	}
	precio_final +=valor;
	return true;
}

const char * cPeluche::getUnidad_relleno()
{
    return unidad_relleno;
}

float cPeluche::getPrecio_relleno()
{
    return precio_relleno;
}

float cPeluche::getPeso_relleno()
{
    return peso_relleno;
}

float cPeluche::getPeso_final()
{
    return peso_final;
}

float cPeluche::getPrecio_final()
{
    return precio_final;
}

cPeluche::~cPeluche()
{
    cPrenda::~cPrenda();
    cPrenda::liberar(&unidad_relleno);
}
