//Ejecicio2 de la Videoconferencia
#include <iostream> //Esta es la librería que permite la entrada y salida de datos 
#include<stdlib.h> 
#include<windows.h> //Sirve para utilizar la funcion system("cls") para limpiar la pantalla
#include <iomanip>	// Esta libreria permita hacer uso de setfill()=Rellenar y setw()
/*using std::setfill;
using std::setw;*/

using namespace std;

// Definición del tipo de dato abstracto (ADT) Tiempo
class Tiempo{
	private:
		int hora; // 0 - 23 (formato de reloj de 24 horas)
		int minuto; // 0 - 59
		int segundo; // 0 - 59
	public:	
		Tiempo( ); // constructor
		void capturarDatos();
		void estableceHora(int,int,int); // establece hora, minuto, segundo		
		void imprimeUniversal(); // imprime el tiempo en formato universal
		void imprimeEstandar(); // imprime el tiempo en formato estándar
}; // fin de la clase Tiempo

/*el constructor Tiempo inicializa cada dato miembro en cero y
  garantiza que los objetos Tiempo comiencen en un estado consistente*/
Tiempo::Tiempo(){//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	hora = minuto = segundo = 0;
} // fin del constructor Tiempo

/* establece un nuevo valor para Tiempo de acuerdo con la hora universal, realiza la validación
 de los valores de datos y establece los valores no válidos en cero */
 
 void Tiempo::estableceHora(int _hora,int _minuto,int _segundo){//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	hora = ( _hora >= 0 && _hora < 24 ) ? _hora : 0;
	minuto = ( _minuto >= 0 && _minuto < 60 ) ? _minuto : 0;
	segundo = ( _segundo >= 0 && _segundo < 60 ) ? _segundo : 0;
} // fin de la función estableceHora

int validar_num(char numero[50]){	/////////////////////////////////////////////////////////////////////////////////////
 int i = 0, sw = 0, j; 
 j=strlen(numero); //tamaño de la cadena
 while (i<j && sw==0) {
  if(isdigit(numero[i])!=0)  {
   i++;
  }
  else  {
   sw = 1;
  }
 }
return sw; 
}

// función para capturar datos de hora
void Tiempo::capturarDatos(){//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	char _hr[10],_mn[10],_sg[10];
	int hr=0, mn=0, sg = 0,sw=0;	
	char _opcion[10];
	int opcion=0;
	do{
	cout<<"\n\tRESTAURANTE GRUPO1"<<endl;
	cout<<"Escoja una opcion."<<endl;
	cout<<"1. Desea reservar una cita."<<endl;
	cout<<"2. Salir"<<endl;	
		cout<<"Opcion: " ;
		cin.getline(_opcion,10,'\n');
		sw = validar_num(_opcion);
		if(sw==0){
			opcion = atoi(_opcion);
		}
		system("cls");	
	}while(opcion != 1 && opcion != 2);
	
	
	switch(opcion){
		case 1:					
		do{
			cout<<"\n\tBIENVENIDO A SU RESTAURANTE GRUPO1 \n\t \t\"Reserve su cita\" "<<endl;
			 fflush(stdin);
			 do{
			cout <<"\nDigite la Hora      (0 - 23): ";	//////////////////////////////////////////				
			cin.getline(_hr,10,'\n');
			sw = validar_num(_hr);
			if(sw ==0){
				hr = atoi(_hr);
				}else{
					cout<<"Ingrese la hora correctamente";
				}		
			}while(sw!=0);
			
			do{
				cout <<"\nDigite los Minutos  (0 - 59): ";	//////////////////////////////////////////
			cin.getline(_mn,10,'\n');
			sw = validar_num(_mn);
			if(sw == 0){
				mn = atoi(_mn);
			}else{
				cout<<"Ingrese los minutos correctamente!";
				
			}
			}while(sw !=0);				
			
			do{
				cout <<"\nDigite los Segundos (0 - 59): ";	/////////////////////////////////////////////
				cin.getline(_sg,10,'\n');
				sw = validar_num(_sg);
				if(sw == 0){
					sg = atoi(_sg);
				}else{
					cout<<"Ingrese los segundos correctamente!";
					
				}
			}while(sw !=0);
						
			if(sg<0||sg>59||mn<0||mn>59||hr<0||hr>23){
				system("cls");
				cout<<"\n\n¡¡¡¡ATENCION:  Algo anda mal "<<endl;
				cout<<"Introduzca los datos correctamente"<<endl;				
			}			
		}while(sg<0||sg>59||mn<0||mn>59||hr<0||hr>23);
		
		system("cls");	
		estableceHora(hr,mn,sg);
		cout<<"\n\n\tBIENVENIDO A SU RESTAURANTE GRUPO1"<<endl;
		cout << "\nSu cita a sido reservada EXITOSAMENTE "<<endl;			
		imprimeUniversal();		
		imprimeEstandar();
		cout<<"\n\nNo olvide acudir a su cita"<<endl;
		cout<<"\n\t-----------Le Esperamos!-----------"<<endl;
		cout << "\n"<<endl;
		
			break;

		case 2: system("cls");
		cout<<"\n\n\tRESTAURANTE GRUPO1"<<endl;
		cout<<"\nNo a concretado ninguna cita"<<endl;
		cout<<"\n--------HASTA PRONTO--------"<<endl;
			cout << "\n"<<endl;
			break;			
	default:"Elija una opcion";
	}
} // fin de la funcion capturarDatos

// imprime Tiempo en formato universal
void Tiempo::imprimeUniversal(){//// Imprimiendo los datos de la cena      xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	cout << "\n\tHora universal:";
	cout << setfill( '0' ) 				//setfill rellena con el string cero ('0') donde haya datos con un digito
	<< setw( 2 ) << hora << ":" 	//Sirve para dar formato a los numeros (sewt 2 = 00) (sewt 3 = 000)
	<< setw( 2 ) << minuto << ":"
	<< setw( 2 ) << segundo;
} // fin de la función imprimeUniversal

// imprime Tiempo en formato estándar
void Tiempo::imprimeEstandar(){
	cout << "\n\tHora estandar :";
	cout<< setfill( '0' )	//rellena los datos con el cero donde haya un solo digito
		<< setw( 2 )<<( ( hora == 0 || hora == 12 ) ? 12 : hora % 12 )<< ":" 	 	 				
		<< setw( 2 ) << minuto << ":"	//el formato de hora es de dos digitos y son rellenados por setfill (1 digito)
	 	<< setw( 2 ) << segundo
		<< ( hora < 12 ? " AM" : " PM" );
} // fin de la función imprimeEstandar

/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
  xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx */
int main(){
	//int hora,minuto,segundo;
Tiempo horaCita = Tiempo(); // crea la instancia del objeto t de la clase Tiempo
// Capturando los datos de la hora de la cena
horaCita.capturarDatos(); // Imprime la hora utilizando las funciones	

system ("pause");
return 0;
} // fin de main

