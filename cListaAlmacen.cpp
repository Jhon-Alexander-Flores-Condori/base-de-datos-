#include "cListaAlmacen.hpp"
#include "cAlmacen.hpp"
#include <iostream>

cListaAlmacen::cListaAlmacen()
{
    llenado_nullptr();
    size_storage = -1;
    size_code = -1;
}

cListaAlmacen::cListaAlmacen(cAlmacen * nuevo, int tam, char *code, int tam_cod)
{
    llenado_nullptr();

    if(llenado_almacen(nuevo, tam))
    {
        std::cout<<"ALMACEN LLENADO"<<std::endl;
    }
    else
    {
        std::cout<<"ERROR AL LLENAR ALMACEN"<<std::endl;
    }

    if(llenado_codigo(code, tam_cod))
    {
        std::cout<<"CODIGO LLENADO"<<std::endl;
    }
    else
    {
        std::cout<<"ERROR CODIGO NO LLENADO"<<std::endl;
    }
}

void cListaAlmacen::llenado_nullptr()
{
    manyStorages = nullptr;
    codigo = nullptr;
}

bool cListaAlmacen::llenado_almacen(cAlmacen *nuevo, int value)
{
    if(llenado_size(value))
    {
        crear_memoria(size_storage, &manyStorages);

        for(int i=0;i<size_storage;i++)
        {
            *(manyStorages+i) = *(nuevo+i);
        }
        return true;
    }
    return false;
}

bool cListaAlmacen::llenado_codigo(char *code, int size)
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

bool cListaAlmacen::llenado_size(int valor)
{
    if(valor<1)
    {
        std::cout<<"invalido"<<std::endl;
        size_storage =-1;
        return false;
    }

    size_storage = valor;
    return true;
}

bool cListaAlmacen::llenado_size_cod(int size, char * cadena)
{
	if(size <= 1)//o por deafult o no lo lleno
	{
		size = contador(cadena);
		if(size<=1) // still 0, no se crea nada
		{
			size_code = -1;
            std::cout<<"CADENA DE LONGITUD 0 INVIABLE"<<std::endl;
			return false;
		}
	}

	size_code = size;
	return true;
}

cAlmacen* cListaAlmacen::getStorage()
{
    return manyStorages;
}

char* cListaAlmacen::getCodigo()
{
    return codigo;
}

int cListaAlmacen::getSize()
{
    return size_storage;
}

int cListaAlmacen::getSize_code()
{
    return size_code;
}

void cListaAlmacen::print()
{

    std::cout<<"N de sub-almacenes en "<<codigo<< " es: "<<size_storage<<std::endl;
    std::cout<<"tamaño de codigo: "<<size_code<<std::endl;
    std::cout<<"direccion de memoria general: "<<manyStorages<<std::endl;
}

void cListaAlmacen::buscarCodigo(char * codigo, int * temp)//40
{
    int indexTemp = 0;

    for(int i=0;i<size_storage;i++)
    {
        bool flag = true;

        //direccion de memoria
        char *direccion = (*(manyStorages + i)).getCodigo();   //manyStorages+i)->codigo;
        cAlmacen valor = *(manyStorages+i);
        int max = valor.getSize_cod();

        for(int a =0;a<max;a++)
        {
            if(  *(codigo+a) != *(direccion+a))
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

void cListaAlmacen::buscarFecha(char * codigo,int fin, int inicio, int* temp)
{
    int indexTemp = 0;
    int intervalo = (fin - inicio);
    for(int i=0;i<size_storage;i++)
    {
        bool flag = true;

        //direccion de memoria
        char *direccion = (*(manyStorages + i)).getFecha();   //manyStorages+i)->codigo;

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

void cListaAlmacen::buscarNombre(char * codigo,int fin, int inicio, int* temp)
{
    int indexTemp = 0;
    int intervalo = (fin - inicio);
    for(int i=0;i<size_storage;i++)
    {
        bool flag = true;

        //direccion de memoria
        char *direccion = (*(manyStorages + i)).getNombre();   //manyStorages+i)->codigo;

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

bool cListaAlmacen::addContent(cAlmacen *nuevo, int add)
{
    cAlmacen *temp = nullptr;
    int oldSize = size_storage;

    if(nuevo == nullptr || add == 0)
    {
        return false;
    }

    size_storage +=add;

    crear_memoria(size_storage, &temp);

    for(int i=0;i<(oldSize);i++)
    {
        *(temp+i) = *(manyStorages+i);
    }

    for(int i=0;i<add;i++)
    {
        *(temp+oldSize+i) = *(nuevo+i);
    }

    liberar_memoria(&manyStorages);

    manyStorages = temp;

    return true;

}

bool cListaAlmacen::deleteContent(int begin, int end)//index, 3 a 4, entonce 2 a 3includio
{
    cAlmacen *temp = nullptr;
    int intervalo = (end-begin+1);
    int oldSize = size_storage;
    int tempIndex =0;

    if(intervalo<=0 || end>size_storage || begin<1 || begin>end)
    {   return false;   }

    size_storage-=intervalo;
    crear_memoria(size_storage, &temp);

    for(int i=0;i<oldSize;i++)
    {
        if(i<= (end-1) && i>=(begin-1))
        {
            continue;
        }
        *(temp+tempIndex) = *(manyStorages+i);
        tempIndex++;
    }

    liberar_memoria(&manyStorages);
    manyStorages = temp;
    return true;
}

void cListaAlmacen::copiar( char *root, char *destino, int tam)
{
	for(int i=0;i<tam;i++)
	{
		*(destino+i) = *(root+i);
	}
	*(destino+(tam-1)) = '\0';//asegurar
}

int cListaAlmacen::contador(const char * cadena)
{
	int fin =0;
	while( *(cadena+fin) != '\0')
	{
		fin++;
	}
	return fin+1;
}

void cListaAlmacen::crear_memoria_arrays(int tam, char **destino)
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

void cListaAlmacen::crear_memoria(int tam, cAlmacen **destino)
{
    if( *destino != nullptr)
    {   liberar_memoria(destino);    }

    if(tam>=1)
    {
        *destino = new cAlmacen[tam];
    }
    else
    {
        *destino = nullptr;
        std::cout<<"size no valid -- no arrange of new memory in manyStorages"<<std::endl;
    }

}

void cListaAlmacen::liberar_arrays(char **target)
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

void cListaAlmacen::liberar_memoria(cAlmacen **target)
{
    if(*target != nullptr)
    {
        delete[] *target;
        *target = nullptr;
    }
    else
    {
        std::cout<<"Already empty!"<<std::endl;
    }

}

cListaAlmacen::~cListaAlmacen()
{
    liberar_memoria(&manyStorages);
    liberar_arrays(&codigo);
}
