#include "cAccesorio.hpp"
#include "cPrenda.hpp"
#include <iostream>

cAccesorio::cAccesorio() : cPrenda()
{
	cPrenda::fecha.actualizarFecha();
	llenado_nullptr();
	size_base = -1;
	precio_base = -1.0;
	precio_final = -1.0;
}

cAccesorio::cAccesorio(char * name, char *code, char * measure, int tam_cod, int tam_name,
                    int tam_measure,float money, char *base_material, int tam_base,
					char *utility_material, int tam_utility, float money_base, float money_final)
			: cPrenda(name, code, measure, tam_cod,tam_name, tam_measure, money)
{
	cPrenda::fecha.actualizarFecha();
	llenado_nullptr();
	
	if(llenado_material_base(base_material, tam_base))
	{
		std::cout<<"MATERIAL BASE LLENADO CON EXITO"<<std::endl;
	}
	else
	{
		std::cout<<"MATERIAL BASE NO LLENADO CON EXITO"<<std::endl;
	}
	if(llenado_utilidad(utility_material, tam_utility))
	{
		std::cout<<"UTILIDAD LLENADO CON EXITO"<<std::endl;
	}
	else
	{
		std::cout<<"UTILIDAD LLENADO NO CON EXITO"<<std::endl;
	}

	if(llenado_precio_base(money_base))
	{
		std::cout<<"PRECIO DE LA BASE LLENADO CON EXITO"<<std::endl;
	}
	else
	{
		std::cout<<"PRECIO DE LA BASE NO LLENADO CON EXITO"<<std::endl;
	}
	
}

cAccesorio::cAccesorio(const cAccesorio &obj) : cPrenda(obj)
{
    llenado_nullptr();

	if(asignar_valores(obj)) {
		std::cout << "SE LOGRO" << std::endl;
	} else {
		std::cout << "NO SE LOGRO" << std::endl;
	}

	std::cout << "CONSTRUCTOR DE COPIA" << std::endl;
}

cAccesorio& cAccesorio::operator=(const cAccesorio &obj)
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


bool cAccesorio::asignar_valores(const cAccesorio &obj)
{
	cPrenda::fecha.actualizarFecha();
	bool flag = true;
	fecha = obj.fecha;
	llenado_nullptr();

	if(llenado_material_base(obj.material_base,obj.size_base))
	{
		std::cout<<"MATERIAL BASE LLENADO CON EXITO"<<std::endl;
	}
	else
	{
		std::cout<<"MATERIAL BASE NO LLENADO CON EXITO"<<std::endl;
		flag = false;
	}
	if(llenado_utilidad(obj.utilidad, obj.size_utilidad))
	{
		std::cout<<"UTILIDAD LLENADO CON EXITO"<<std::endl;
	}
	else
	{
		std::cout<<"UTILIDAD LLENADO NO CON EXITO"<<std::endl;
		flag = false;
	}

	if(llenado_precio_base(obj.precio_base))
	{
		std::cout<<"PRECIO DE LA BASE LLENADO CON EXITO"<<std::endl;
	}
	else
	{
		std::cout<<"PRECIO DE LA BASE NO LLENADO CON EXITO"<<std::endl;
		flag = false;
	}
	return flag;
}


void cAccesorio::llenado_nullptr()
{
	material_base = nullptr;
	utilidad = nullptr;
	
}

bool cAccesorio::llenado_utilidad(char *cadena, int size)
{
	cPrenda::fecha.actualizarFecha();
    if(cadena != nullptr)
    {
        if(utilidad != nullptr)
        {   cPrenda::liberar(&utilidad);  }

        if(llenado_size_utilidad(size,cadena))
        {
            cPrenda::crear_memoria(size_base, &utilidad);
            cPrenda::copiar(cadena, utilidad, size_utilidad);
            return true;
        }
        else
        {   return false;   }
    }
    return false;
}

bool cAccesorio::llenado_material_base(char *cadena, int size)
{
	cPrenda::fecha.actualizarFecha();
    if(cadena != nullptr)
    {
        if(material_base!= nullptr)
        {   cPrenda::liberar(&material_base);  }

        if(llenado_size_base(size,cadena))
        {
            cPrenda::crear_memoria(size_base, &material_base);
            cPrenda::copiar(cadena, material_base, size_base);
            return true;
        }
        else
        {   return false;   }
    }
    return false;
}

bool cAccesorio::llenado_size_base(int size, char *cadena)
{
	cPrenda::fecha.actualizarFecha();
    if(size <= 1)//o por deafult o no lo lleno
    {
        size = cPrenda::contador(cadena);
        if(size<=1) // still 0, no se crea nada
        {
            size_base = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
            return false;
        }
    }

    size_base = size;
    return true;
}

bool cAccesorio::llenado_size_utilidad(int size, char *cadena)
{
	cPrenda::fecha.actualizarFecha();
    if(size <= 1)//o por deafult o no lo lleno
    {
        size = cPrenda::contador(cadena);
        if(size<=1) // still 0, no se crea nada
        {
            size_utilidad = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
            return false;
        }
    }

    size_utilidad = size;
    return true;
}

bool cAccesorio::llenado_precio_base(float numero)
{
	cPrenda::fecha.actualizarFecha();
    if(numero<=0.0)
	{
		precio_base = -1.0;
		return false;
	}
	precio_base = numero;
	return true;
}

bool cAccesorio::llenado_precio_final()
{
	cPrenda::fecha.actualizarFecha();
    float valor = cPrenda::getPrecio_unitario();

    if(valor<=0.0)
	{
		std::cout<<"Peso unitario cprenda invalido"<<std::endl;
        return false;
	}
	precio_final +=valor;
	return true;
	
}
		
const char *cAccesorio::getMaterial_base()
{
	return material_base;
}


const char *cAccesorio::getUtilidad()
{
	return utilidad;
}

int cAccesorio::getSize_base()
{
	return size_base;
}

int cAccesorio::getSize_utilidad()
{
	return size_utilidad;
}

float cAccesorio::getPrecio_base()
{
	return precio_base;
}

float cAccesorio::getPrecio_final()
{
	return precio_final;
}

cAccesorio::~cAccesorio()
{
	cPrenda::liberar(&material_base);
	cPrenda::liberar(&utilidad);
}
