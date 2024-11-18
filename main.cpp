//#include "cPrenda.hpp"
#include "cAlmacen.hpp"
#include "cListaAlmacen.hpp"

#include <iostream>
#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_COMMAND "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__)
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_COMMAND "clear"
#endif



void market()
{
	std::system(CLEAR_COMMAND);            // Comando para borrar todo el contenido de la pantalla
    std::cout << "\x1B[H";          // Codigo para colocar el cursor en el canto superior izquierdo
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << "\x1B[38;5;227m   _______  __   __  _______  ______    _______  _______  _______   _______  _______  __   __  _______  ___  ___     " << std::endl;
	std::cout << "\x1B[38;5;227m  |       ||  |_|  ||       ||    _ |  |       ||       ||   _   | |       ||       ||  |_|  ||       ||   ||   |  " << std::endl;
	std::cout << "\x1B[38;5;227m  |    ___||       ||    _  ||   | ||  |    ___||  _____||  |_|  | |_     _||    ___||       ||_     _||   ||   |      " << std::endl;
	std::cout << "\x1B[38;5;227m  |   |___ |       ||   |_| ||   |_||_ |   |___ | |_____ |       |   |   |  |   |___ |       |  |   |  |   ||   |" << std::endl;
	std::cout << "\x1B[38;5;227m  |    ___||       ||    ___||    __  ||    ___||_____  ||       |   |   |  |    ___| |     |   |   |  |   ||   |___ " << std::endl;
	std::cout << "\x1B[38;5;227m  |   |___ | ||_|| ||   |    |   |  | ||   |___  _____| ||   _   |   |   |  |   |___ |   _   |  |   |  |   ||       |" << std::endl;
	std::cout << "\x1B[38;5;227m  |_______||_|   |_||___|    |___|  |_||_______||_______||__| |__|   |___|  |_______||__| |__|  |___|  |___||_______|" << std::endl;
	std::cout << " \x1B[m" << std::endl;
}
void menu()
{
	std::cout << " " << std::endl;          
	std::cout << "\x1B[38;5;222m             ************************************************** " << std::endl;
	std::cout << "\x1B[38;5;222m             |                                                | " << std::endl;
	std::cout << "\x1B[38;5;222m             |" << "                      MENU                      " << "|" << std::endl;
	std::cout << "\x1B[38;5;222m             |" << "   1 PARA INGRESAR INFORMACION DEL CLIENTE      " << "|" << std::endl;
	std::cout << "\x1B[38;5;222m             |" << "   2 PARA INGRESAR INFORMACION DE PRENDAS       " << "|"  << std::endl;
	std::cout << "\x1B[38;5;222m             |" << "   3 PARA INGRESAR INFORMACION DE ALMACENES     " << "|"  << std::endl;
	std::cout << "\x1B[38;5;222m             |" << "   4 PARA SALIR                                 " << "|"  << std::endl;
	std::cout << "\x1B[38;5;222m             |                                                | \x1B[m" << std::endl;
	std::cout << "\x1B[38;5;222m             ************************************************** \x1B[m" << std::endl;
}
void imprimir_cliente()
{
		std::cout << " " << std::endl;
		std::cout << " " << std::endl;
		std::cout << "\x1B[38;5;117m   _______  ___      ___  _______  __    _  _______  _______ " << std::endl;
		std::cout << "\x1B[38;5;117m  |       ||   |    |   ||       ||  |  | ||       ||       |" << std::endl;
		std::cout << "\x1B[38;5;117m  |      _||   |    |   ||    ___||   |_| ||_     _||    ___|" << std::endl;
		std::cout << "\x1B[38;5;117m  |     |  |   |    |   ||   |___ |       |  |   |  |   |___ " << std::endl;
		std::cout << "\x1B[38;5;117m  |     |  |   |___ |   ||    ___||  _    |  |   |  |    ___|" << std::endl;
		std::cout << "\x1B[38;5;117m  |     |_ |       ||   ||   |___ | | |   |  |   |  |   |___ " << std::endl;
		std::cout << "\x1B[38;5;117m  |_______||_______||___||_______||_|  |__|  |___|  |_______|" << std::endl;
		std::cout << " " << std::endl;
		std::cout << " " << std::endl;
}

void imprimir_prenda()
{
		std::cout << " " << std::endl;
		std::cout << " " << std::endl;
		std::cout << "\x1B[38;5;211m   _______  ______    _______  __    _  ______   _______  _______ " << std::endl;
		std::cout << "\x1B[38;5;211m  |       ||    _ |  |       ||  |  | ||      | |   _   ||       |" << std::endl;
		std::cout << "\x1B[38;5;211m  |    _  ||   | ||  |    ___||   |_| ||  _    ||  |_|  ||  _____|" << std::endl;
		std::cout << "\x1B[38;5;211m  |   |_| ||   |_||_ |   |___ |       || | |   ||       || |_____ " << std::endl;
		std::cout << "\x1B[38;5;211m  |    ___||    __  ||    ___||  _    || |_|   ||       ||_____  |" << std::endl;
		std::cout << "\x1B[38;5;211m  |   |    |   |  | ||   |___ | | |   ||       ||   _   | _____| |" << std::endl;
		std::cout << "\x1B[38;5;211m  |___|    |___|  |_||_______||_|  |__||______| |__| |__||_______|" << std::endl;
		std::cout << " " << std::endl;
		std::cout << " \x1B[m" << std::endl;
}

void imprimir_almacen()
{
		std::cout << " " << std::endl;
		std::cout << " " << std::endl;
		std::cout << "\x1B[38;5;149m   _______  ___      __   __  _______  _______  _______  __    _ " << std::endl;
		std::cout << "\x1B[38;5;149m  |   _   ||   |    |  |_|  ||   _   ||       ||       ||  |  | |" << std::endl;
		std::cout << "\x1B[38;5;149m  |  |_|  ||   |    |       ||  |_|  ||      _||    ___||   |_| |" << std::endl;
		std::cout << "\x1B[38;5;149m  |       ||   |    |       ||       ||     |  |   |___ |       |" << std::endl;
		std::cout << "\x1B[38;5;149m  |       ||   |___ |       ||       ||     |  |    ___||  _    |" << std::endl;
		std::cout << "\x1B[38;5;149m  |   _   ||       || ||_|| ||   _   ||     |_ |   |___ | | |   |" << std::endl;
		std::cout << "\x1B[38;5;149m  |__| |__||_______||_|   |_||__| |__||_______||_______||_|  |__|" << std::endl;
		std::cout << " " << std::endl;
		std::cout << " \x1B[m" << std::endl;
}

void imprimir()
{
	//cPrenda prenda1;
	/*cAlmacen almacen1;

	
	market();
	
	int comando_elegido {0};
	
	do{
		menu();
		std::cout << " " << std::endl;           
		std::cout << " " << std::endl;  
		std::cout << "\x1B[38;5;227m   COMANDO ELEGIDO: ";
		std::cin >> comando_elegido;
		
				
		if (comando_elegido == 1)
		{
    std::cout<<"lola"<<std::endl;
		}

		else if (comando_elegido == 2)
		{
			std::system(CLEAR_COMMAND); 
			
			imprimir_prenda();

			std::cout << " " << std::endl; 
			std::cout << "\x1B[38;5;211m    *" <<"    CANTIDAD DE LA PRENDA: \x1B[m" ;
			std::cin >> prenda1.cantidad;
		
			std::cout << "\x1B[38;5;211m    *" << "    CANTIDAD DISTRIBUIDA: \x1B[m";
			std::cin >> prenda1.monto_total;

			std::cout << "\x1B[38;5;211m    *" << "    PRECIO UNITARIO: \x1B[m";
			std::cin >> prenda1.precio_unitario;
		
			
			std::cout << " " << std::endl;           
			std::cout << " " << std::endl; 
			std::cout << "\x1B[38;5;113m     " << "   !! SE GUARDO CON EXITO LA PRENDA !! \x1B[m"<< std::endl;
			std::cout << " " << std::endl;           
			std::cout << " " << std::endl; 
			std::cout << "\x1B[38;5;211m    *" << "  SOBRE LA PRENDA: \x1B[m"<< std::endl;
			std::cout << " " << std::endl;
			std::cout << "\x1B[38;5;211m        " << " - CANTIDAD DE LA PRENDA: " << "\t\x1B[m" << prenda1.cantidad << std::endl;
			std::cout << "\x1B[38;5;211m        " << " - CANTIDAD DISTRIBUIDA: " << "\t\x1B[m" <<  prenda1.monto_total<< std::endl; 
			std::cout << "\x1B[38;5;211m        " << " - PRECIO UNITARIO: " << "\t\t\x1B[m" << prenda1.precio_unitario << std::endl;
			
			
		}	

		else if (comando_elegido == 3)
		{
			std::system(CLEAR_COMMAND); 
			
			imprimir_almacen();
			
			char temp[30] {"-"};
			int num{0};
			
			int tam_nom {-1}, tam_codigo {-1};
			
			std::cout << " " << std::endl; 
			std::cout << "\x1B[38;5;149m    *" <<"   NOMBRE DEL ALMACEN: \x1B[m" ;
			std::cin >> temp;
			
			almacen1.llenado_nombre(temp);
			
			std::cout << "\x1B[38;5;149m    *" << "   CODIGO DEL ALMACEN: \x1B[m";
			std::cin >> temp;
			
			almacen1.llenado_codigo(temp);

			
			std::cout << " " << std::endl;           
			std::cout << " " << std::endl; 
			std::cout << "\x1B[38;5;11m     " << "   !! SE GUARDO CON EXITO EL ALMACEN !! \x1B[m"<< std::endl;
			std::cout << " " << std::endl;           
			std::cout << " " << std::endl; 
			std::cout << "\x1B[38;5;149m    *" << "  LISTA DE ALMACENES: \x1B[m"<< std::endl;
			std::cout << " " << std::endl;
			std::cout << "\x1B[38;5;149m     |    NOMBRE    |    CODIGO     | FECHA INGRESO  |  SUBALMACEN   |     CODIGO    | \x1B[m"<< std::endl;
			std::cout << "\x1B[38;5;255m        " << almacen1.nombre << "\t \t" << almacen1.codigo << "\t \t" << "requested" <<"\x1B[m"<< std::endl;
						
			std::cout << "Hubo error? , ingrese de nuevo nombre ";
			std::cin >> temp;
			
			almacen1.llenado_nombre(temp);
			
			std::cout << "\x1B[38;5;149m     |    NOMBRE    |    CODIGO     | FECHA INGRESO  |  SUBALMACEN   |     CODIGO    | \x1B[m"<< std::endl;
			std::cout << "\x1B[38;5;255m        " << almacen1.nombre << "\t \t" << almacen1.codigo << "\t \t" << "requested" <<"\x1B[m"<< std::endl;

			almacen1.print();
			
		}
	}while(comando_elegido != 4);
	*/

	
}

int main()
{
	//imprimir();
	/*
	cAlmacen primero;
	primero.print();

	std::cout<<""<<std::endl;
	char temp[40];
	std::cout<<"NOMBRE: ";
	std::cin>> temp;
	std::cout<<""<<std::endl;


	std::cout<<"codigo: ";
	std::cin>> temp;
	std::cout<<""<<std::endl;


	primero.llenado_nombre(temp);
	primero.llenado_codigo(temp);
	primero.print();


	cAlmacen segundo = primero;

	segundo.print();

	std::cout<<"NOMBRE: ";
	std::cin>> temp;
	std::cout<<""<<std::endl;
	segundo.llenado_nombre(temp);
	std::cout<<"imprimir primero "<<std::endl;
	primero.print();
	*/
	cListaAlmacen nuevo[2];

	nuevo[1].print();
	nuevo[0].print();


    return 0;
}
