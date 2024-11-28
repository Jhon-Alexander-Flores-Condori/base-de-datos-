#include "cListaPeluche.hpp"

cListaPeluche::cListaPeluche() : cListaPrenda()
{
    llenado_default();
    precio_total = -1.0;
    size_material_fill = -1;
}

void cListaPeluche:: llenado_default()
{
    material_fill = nullptr;
}

cListaPeluche::cListaPeluche(cPrenda * nuevo, int tam, char *code, char * source,
                             char * fill, int tam_code, int tam_source, int tam_fill)
            : cListaPrenda(nuevo, tam, code, source, tam_code, tam_source)
{
    llenado_default();

    if(llenado_maFill(fill, tam_fill))
    {
        std::cout<<"LOGRADO LLENAR RELLENO"<<std::endl;
    }
    else
    {
        std::cout<<"NO LOGRADO LLENAR RELLENO"<<std::endl;
    }
}

bool cListaPeluche::llenado_maFill(char *code, int size)
{
	if(code != nullptr)//existe, puedes copiar
	{
		//si nombre esta ocupado
		if(material_fill != nullptr) //liberar memoria de nombre
			{  cListaPrenda::liberar_arrays(&material_fill); }

		if(llenado_size_material_fill(size, code))
		{
			crear_memoria_arrays(size_code, &codigo);
			copiar(code, codigo, size_code);
			return true;
		}
	}
	std::cout<< "ERROR AL LLENAR CODIGO" <<std::endl;
	return false;
}

bool cListaPeluche::llenado_size_maFill(int size, char * cadena)
{
    if(size <= 1)//o por deafult o no lo lleno
	{
		size = cListaPrenda::contador(cadena);
		if(size<=1) // still 0, no se crea nada
		{
			size_material_fill = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
			return false;
		}
	}

	size_material_fill = size;
	return true;
}

const char* cListaPeluche::getRelleno()
{
    return material_fill;
}

int cListaPeluche::getRelleno_size()
{
    return size_material_fill;
}

void cListaPeluche::crear_memoria()
{
    if( manyClothes!= nullptr)
    {   liberar_memoria();    }

    if(size_storage>=1)
    {
        manyClothes= new cPeluche[size_storage];
    }
    else
    {
        manyClothes = nullptr;
        std::cout<<"size no valid -- no arrange of new memory in manyStorages"<<std::endl;
    }
}
















