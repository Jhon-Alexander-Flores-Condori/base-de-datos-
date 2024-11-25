#include "cListaPrenda.hpp"
#include "cPrenda.hpp"

#include <iostream>

cListaPrenda::cListaPrenda()
{
    llenado_nullptr();
    size_storage = -1;
    size_code = -1;
    precio_total = -1.0;
}

cListaPrenda::cListaPrenda(cPrenda * nuevo, int tam, char *code, char * source)
{
    llenado_nullptr();

    if(llenado_prenda(nuevo, tam))
    {
        std::cout<<"LOGRADO LLENAR PRENDA"<<std::endl;
    }
    else
    {
        std::cout<<"NO LOGRADO LLENAR PRENDA"<<std::endl;
    }
    if(llenado_codigo(codigo))
    {
        std::cout<<"LLENADO CODIGO"<<std::endl;
    }
    else
    {
        std::cout<<"NO LLENADO CODIGO"<<std::endl;
    }
    if(llenado_material(source))
    {
        std::cout<<"LLENADO MATERIAL"<<std::endl;
    }
    else
    {
        std::cout<<"NO LLENADO MATERIAL"<<std::endl;
    }

}

void cListaPrenda::llenado_nullptr()
{
    manyClothes = nullptr;
    codigo = nullptr;
    material = nullptr;
}

bool cListaPrenda::llenado_prenda(cPrenda * nuevo, int value)
{
    if(llenado_size(value))
    {
        crear_memoria();
        for(int i=0;i<size_storage;i++)
        {
            *(manyClothes+i) = *(nuevo+i);
        }

        return true;
    }
    return false;
}

bool cListaPrenda::llenado_codigo(char *code, int size)
{
	if(code != nullptr)//existe, puedes copiar
	{
		//si nombre esta ocupado
		if(codigo != nullptr) //liberar memoria de nombre
			{  liberar_arrays(&codigo); }

		if(llenado_size_cod(size, code))
		{
			crear_memoria_arrays(size_code, &codigo);
			copiar(code, codigo, size_code);
			return true;
		}
	}
	std::cout<< "ERROR AL LLENAR CODIGO" <<std::endl;
	return false;

}

bool cListaPrenda::llenado_precio_total()
{
    for(int i=0;i<size_storage; i++)
    {
        cPrenda valor = *(manyClothes+i);
        precio_total += valor.getPrecio_unitario();
    }
    if(precio_total<1.0)
    {
        return false;
    }
    return true;
}

bool cListaPrenda::llenado_material(char *code, int size)
{
	if(code != nullptr)//existe, puedes copiar
	{
		//si nombre esta ocupado
		if(material != nullptr) //liberar memoria de nombre
			{  liberar_arrays(&material); }

		if(llenado_size_cod(size, code))
		{
			crear_memoria_arrays(size_material, &material);
			copiar(code, material, size_material);
			return true;
		}
	}
	std::cout<< "ERROR AL LLENAR CODIGO" <<std::endl;
	return false;

}

bool cListaPrenda::llenado_size(int valor)
{
    if(valor<1)
    {
        std::cout<<"invalido"<<std::endl;
        return false;
    }

    size_storage = valor;
    return true;
}

bool cListaPrenda::llenado_size_cod(int size, char * cadena)
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

	size_code = size;
	return true;
}

bool cListaPrenda::llenado_size_material(int size, char * cadena)
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

	size_material = size;
	return true;
}

cPrenda* cListaPrenda::getStorage()
{
    return manyClothes;
}
const char* cListaPrenda::getMaterial()
{
    return material;
}

const char* cListaPrenda::getCodigo()
{
    return codigo;
}

int cListaPrenda::getSize()
{
    return size_storage;
}

int cListaPrenda::getSize_code()
{
    return size_code;
}

int cListaPrenda::getSize_material()
{
    return size_material;
}

int cListaPrenda::getPrecio_total()
{
    return precio_total;
}

void cListaPrenda::print()
{

    std::cout<<"N de sub-almacenes en "<<codigo<< " es: "<<size_storage<<std::endl;
    std::cout<<"tamaño de codigo: "<<size_code<<std::endl;
    std::cout<<"direccion de memoria general: "<<manyClothes<<std::endl;
}

void cListaPrenda::buscarTalla(char * codigo, int * temp)//40
{
    int indexTemp = 0;

    for(int i=0;i<size_storage;i++)
    {
        bool flag = true;

        //direccion de memoria
        cPrenda * direccion = (manyClothes + i);   //manyStorages+i)->codigo;
        const char *cadena = (*direccion).getTalla();
        int tope = (*direccion).getSize_talla();

        for(int a =0;a<tope;a++)
        {
            if(  *(codigo + a) == '\0' || *(codigo+a) != *(cadena+a))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            *(temp+ indexTemp) = i;
            indexTemp++;
        }
    }
    if(indexTemp ==0)
    {
        std::cout<<"NO MATCHING STRINGS - CODE"<<std::endl;
    }
}

void cListaPrenda::buscarFecha(char * codigo,int fin, int inicio, int* temp)
{
    int indexTemp = 0;
    int intervalo = (fin - inicio);
    for(int i=0;i<size_storage;i++)
    {
        bool flag = true;

        //direccion de memoria
        const char *direccion = (*(manyClothes + i)).getFecha();   //manyStorages+i)->codigo;

        for(int a =0;a<intervalo;a++, inicio++)
        {
            if(  *(codigo+a) != *(direccion+inicio))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            temp[indexTemp] = i;
            indexTemp++;
        }
    }
    if(indexTemp ==0)
    {
        std::cout<<"NO MATCHING STRINGS - CODE"<<std::endl;
    }
}

void cListaPrenda::buscarColor(char * codigo, int * temp)//40
{
    int indexTemp = 0;

    for(int i=0;i<size_storage;i++)
    {
        bool flag = true;

        //direccion de memoria
        cPrenda * direccion = (manyClothes + i);   //manyStorages+i)->codigo;
        const char *cadena = (*direccion).getColor();
        int tope = (*direccion).getSize_color();

        for(int a =0;a<tope;a++)
        {
            if(  *(codigo + a) == '\0' || *(codigo+a) != *(cadena+a))
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            *(temp+ indexTemp) = i;
            indexTemp++;
        }
    }
    if(indexTemp ==0)
    {
        std::cout<<"NO MATCHING STRINGS - CODE"<<std::endl;
    }
}

bool cListaPrenda::addContent(cPrenda *nuevo, int add)
{
    cPrenda *temp = nullptr;
    int oldSize = size_storage;

    if(nuevo == nullptr || add == 0)
    {
        return false;
    }

    size_storage +=add;

    crear_memoria_np(size_storage, &temp);

    for(int i=0;i<(oldSize);i++)
    {
        *(temp+i) = *(manyClothes+i);
    }

    for(int i=0;i<add;i++)
    {
        *(temp+oldSize+i) = *(nuevo+i);
    }

    liberar_memoria();

    manyClothes = temp;

    return true;

}

void cListaPrenda::crear_memoria_np(int tam, cPrenda ** destino)
{
    if(*destino != nullptr)
    {
        liberar_memoria_np(destino);
    }

    if (tam > 0) 	//nombre
	{	*destino = new cPrenda[tam]; }
	else
	{
		*destino = nullptr;
		std::cout<<"array = 0 bytes?"<< std::endl;
	}
}

void cListaPrenda::liberar_memoria_np(cPrenda ** target)
{
    if (*target != nullptr) {
        delete[] *target; // Libera la memoria asignada a nombre
        *target = nullptr; // Opcional: poner el puntero a nullptr para evitar accesos futuros
    }
    else
    {
        std::cout<<"Already empty!"<<std::endl;
    }
}

bool cListaPrenda::deleteContent(int begin, int end)//index, 3 a 4, entonce 2 a 3includio
{
    cPrenda *temp = nullptr;
    int intervalo = (end-begin+1);
    int oldSize = size_storage;
    int tempIndex =0;

    if(intervalo<=0 || end>size_storage || begin<1 || begin>end)
    {   return false;   }

    size_storage-=intervalo;
    crear_memoria_np(size_storage, &temp);

    for(int i=0;i<oldSize;i++)
    {
        if(i<= (end-1) && i>=(begin-1))
        {
            continue;
        }
        *(temp+tempIndex) = *(manyClothes+i);
        tempIndex++;
    }

    liberar_memoria();

    manyClothes = temp;
    return true;
}

void cListaPrenda::copiar( char *root, char *destino, int tam)
{
	for(int i=0;i<tam;i++)
	{
		*(destino+i) = *(root+i);
	}
	*(destino+(tam-1)) = '\0';//asegurar
}

int cListaPrenda::contador(const char * cadena)
{
	int fin =0;
	while( *(cadena+fin) != '\0')
	{
		fin++;
	}
	return fin+1;
}

void cListaPrenda::crear_memoria_arrays(int tam, char **destino)
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

void cListaPrenda::crear_memoria()
{
    if( manyClothes!= nullptr)
    {   liberar_memoria();    }

    if(size_storage>=1)
    {
        manyClothes= new cPrenda[size_storage];
    }
    else
    {
        manyClothes = nullptr;
        std::cout<<"size no valid -- no arrange of new memory in manyStorages"<<std::endl;
    }

}

void cListaPrenda::liberar_arrays(char **target)
{
    if (*target != nullptr) {
        delete[] *target; // Libera la memoria asignada a nombre
        *target = nullptr; // Opcional: poner el puntero a nullptr para evitar accesos futuros
    }
    else
    {
        std::cout<<"Already empty!"<<std::endl;
    }
}
void cListaPrenda::liberar_memoria()
{
    if(manyClothes != nullptr)
    {
        delete[] manyClothes;
        manyClothes = nullptr;
    }
    else
    {
        std::cout<<"Already empty!"<<std::endl;
    }

}

cListaPrenda::~cListaPrenda()
{
    liberar_memoria();
    liberar_arrays(&codigo);
    liberar_arrays(&material);
}
