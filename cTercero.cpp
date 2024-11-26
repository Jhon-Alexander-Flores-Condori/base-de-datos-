#include "cTercero.hpp"
#include "cCliente.hpp"
#include "cFecha.hpp"
#include <iostream>
#include <ctime>

cTercero::cTercero()
{
    cCliente::fecha.actualizarFecha();
    llenado_nullptr();
    size_factura = -1;
    size_afiliado = -1;
}

cTercero::cTercero(char *name , char *code , char *direccion, int tam_nom, int tam_cod,
                   int tam_direccion, char *relative, char *money, char *id, int tam_relative,
                   int tam_money, tam_id)
        : cCliente(name, code, direccion, tam_nom, tam_cod, tam_direccion);
{
    cCliente::fecha.actualizarFecha();
    llenado_nullptr();

    if(llenado_afiliado(relative, tam_relative))
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    if(llenado_factura(money, tam_money))
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
}

cTercero::cTercero(const cTercero &obj)
{
    if(asignar_valores(obj))
    {
		std::cout << "SE LOGRO" << std::endl;
	}
	else
    {
		std::cout << "NO SE LOGRO" << std::endl;
	}

	std::cout << "CONSTRUCTOR DE COPIA" << std::endl;
}

cTercero& cTercero::operator=(const cTercero &obj)
{
    if(&obj != this) {
        cCliente::operator=(obj);

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

bool cTercero::asignar_valores(const cTercero &obj)
{
    bool flag = true;

    cCliente::fecha.actualizarFecha();
    llenado_nullptr();

    if(llenado_afiliado(obj.afiliado, size_afiliado))
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
        flag = false;
    }
    if(llenado_factura(obj.factura, obj.size_factura))
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
    }
    else
    {
        std::cout<<"UNIDAD PESO RELLENO LLENADO CON EXITO"<<std::endl;
        flag = false;
    }
    return flag;
}

void cTercero::llenado_nullptr()
{
    factura = nullptr;
    afiliado = nullptr;
}

bool cTercero::llenado_factura(char *cadena, int size)
{
    cCliente::fecha.actualizarFecha();
    if(cadena != nullptr)
    {
        if(factura != nullptr)
        {   cCliente::liberar(&factura);  }

        if(llenado_size_factura(size,cadena))
        {
            cCliente::crear_memoria(size_factura, &factura);
            cCliente::copiar(cadena, factura, size_factura);
            return true;
        }
        else
        {   return false;   }
    }
    return false;
}

bool cTercero::llenado_afiliado(char *cadena, int size)
{
    cCliente::fecha.actualizarFecha();
    if(cadena != nullptr)
    {
        if(afiliado != nullptr)
        {   cCliente::liberar(&afiliado);  }

        if(llenado_size_afiliado(size,cadena))
        {
            cCliente::crear_memoria(size_afiliado, &afiliado);
            cCliente::copiar(cadena, afiliado, size_afiliado);
            return true;
        }
        else
        {   return false;   }
    }
    return false;
}

bool cTercero::llenado_size_factura(int size,char *cadena)
{
    cCliente::fecha.actualizarFecha();
    if(size <= 1)//o por deafult o no lo lleno
    {
        size = cCliente::contador(cadena);
        if(size<=1) // still 0, no se crea nada
        {
            size_factura = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
            return false;
        }
    }

    size_factura = size;
    return true;
}

bool cTercero::llenado_size_afiliado(int size,char *cadena)
{
    cCliente::fecha.actualizarFecha();
    if(size <= 1)//o por deafult o no lo lleno
    {
        size = cCliente::contador(cadena);
        if(size<=1) // still 0, no se crea nada
        {
            size_afiliado = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
            return false;
        }
    }

    size_afiliado = size;
    return true;
}

const char * cTercero::getAfiliado()
{
    return afiliado;
}

const char * cTercero::getFactura()
{
    return factura;
}

int cTercero::getSize_factura()
{
    return size_factura;
}

int cTercero::getSize_afiliado()
{
    return size_afiliado;
}


cTercero::~cTercero()
{
    cCliente::liberar(&afiliado);
    cCliente::liberar(&factura);

}







