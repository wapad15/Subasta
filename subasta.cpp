#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

using namespace std;
 int cantidad_ofertantes=0,cantidad_celulares=0 ,cantidad_ofertas=0;
 
	struct ofertante{
		string nombre;
		string cedula;
		string correo;
		string telefono;
		string id_telefono;
		int 	deposito;
		int 	oferta;
	
	};
	
	struct celular{ 
	string id;
    string marca;
    string modelo;
    int costo_base;
	string gama; 
	};
	
	struct oferta{
		int tipo_oferta;
		string cedula;
		
	

	};
	
ofertante ofertantes[1000];
celular celulares[100];
oferta	ofertas[1000];

// prototipos de funciones
int BuscarOfertante(string cedula);
int BuscarCelular(string id);
int BuscarOferta(string cedula);
int tamanoOfertantes(); 
int	tamanoCelulares();
int tamanoOfertas();
void LeerOfertantes();
void LeerCelulares();
void LeerOfertas();
void RegistrarOfertante();
void RegistrarCelular();
void RegistrarOferta();
void GuardarOfertantes();
void GuardarCelulares();
void GuardarOfertas();
void InformacionOfertantes();
void InformacionCelulares();
void InformacionOfertas();


int main(){
bool bandera=false,salir=false;
int opc,opcion;
    
   for(int i=0 ; i<1000 ; i++){    //ciclo for para inicializar todas las posiciones del arreglo con espacios en blanco de los ofertantes
       ofertantes[i].deposito = 0;
       ofertantes[i].correo = " ";
       ofertantes[i].nombre= " ";
       ofertantes[i].telefono= " ";
       ofertantes[i].cedula =" ";
       ofertantes[i].id_telefono= " ";
       ofertantes[i].oferta = 0 ;
   }
   
   for(int i=0 ; i<100 ; i++){   
       celulares[i].id = " ";
       celulares[i].marca = " ";
       celulares[i].modelo = " ";
       celulares[i].gama= " ";
       celulares[i].costo_base= 0;
   }
   
   for(int i=0 ; i<1000 ; i++){    
       ofertas[i].cedula= " ";
       ofertas[i].tipo_oferta= 0;
   }
    
   cantidad_ofertantes = tamanoOfertantes();
   LeerOfertantes();
   
   cantidad_celulares = tamanoCelulares();
   LeerCelulares();
   
   cantidad_ofertas = tamanoOfertas();
   LeerOfertas();
   
 do
    {
        system("cls");
        cin.clear();
        cout << "SUBASTAS DEL PUEBLO" << endl;
        cout << "--------------------" << endl << endl;
        cout << "\t1.- Registrar Ofertantes" << endl;
        cout << "\t2.- Regstrar Celular " << endl;
        cout << "\t3.- Registrar una oferta" << endl;
        cout << "\t4.- Consultas" << endl;
        cout << "\t5.- Vender un celular" << endl;
        cout << "\t6.- Generar archivo de texto para superintendencia de industria y comercio" << endl;
        cout << "\t7.- Editar archivo de texto para superintendencia de industria y comercio" << endl;
        cout << "\t8.- Reiniciar la subasta" << endl << endl;
        cout << "\t9.- Salir" << endl << endl;
        cout << "Elije una opcion: ";
 
        cin >> opc;
 
		switch(opc)
		{
			case 1:
				system("cls");
				RegistrarOfertante();
				
				break;
 
			case 2:
				system("cls");
				RegistrarCelular();
				break;
 
			case 3:
				system("cls");
				RegistrarOferta();
				
				break;
 
			case 4:
				
			
				do
				{
				  system("cls");
				  cout << "CONSULTAS" << endl;
        		  cout << "------------" << endl << endl;
        		  cout << "\t1.- Iformacion de ofertantes" << endl;
       	  	      cout << "\t2.- Informacion de celulares " << endl;
       			  cout << "\t3.- Informacion de subasta" << endl;	
       			  cout << "\t4.- Salir" << endl << endl;
       			  cout << "Elije una opcion: ";
         		cin >> opcion;
       			
       			switch(opcion)
       			{
       				case 1:
       					system("cls");
						InformacionOfertantes();
						getch();
						break;
						
       				case 2:
       					system("cls");
						InformacionCelulares();
						getch();
						break;
						
       				case 3:
       					system("cls");
						InformacionOfertas();
						getch();
						break;
						
       				case 4:
       					salir =true;
						//exit(1);
						break;
       					
       				default:
						system("cls");
						cout << "\t\t Opcion no valida.\a\n";
						getch();
						break;
				   }
				}while(salir!=true);
				
				break;
				
			case 5:
				system("cls");
				cout << "Vender un celular.\n";
				getch();
				break;
			case 6:
				system("cls");
				cout << "Generar archivo de texto para superintendenciar.\n";
				getch();
				break;
				
			case 7:
				system("cls");
				cout << "Editar archivo de texto para superintendenciar.\n";
				getch();
				break;
			
			case 8:
				system("cls");
				cout << "Reiniciar la subasta.\n";
				getch();
				break;
					
			case 9:
				bandera=true;
				//exit(1);
				break;
 
			default:
				system("cls");
				cout << "\t\t Opcion no valida.\a\n";
				getch();
				break;
		}
    }while(bandera!=true);
 
 
 
 }
 
  int tamanoOfertantes(){
   int registros=0;
   string linea;
   ifstream entrada;
   entrada.open("ofertantes.txt");
   if (entrada.good()) {
      while(!entrada.eof()){
      getline(entrada, linea);
      if(linea!=" ")
          registros++;
      }
   }
   else{
      cout << "\n*** Error en la apertura del archivo ***\n\n" ;
   }
   entrada.close();
   registros--;
   return registros;
  }
  
  int	tamanoCelulares(){
   int registros=0;
   string linea;
   ifstream entrada;
   entrada.open("celulares.txt");
   if (entrada.good()) {
      while(!entrada.eof()){
      getline(entrada, linea);
      if(linea!=" ")
          registros++;
      }
   }
   else{
      cout << "\n*** Error en la apertura del archivo ***\n\n" ;
   }
   entrada.close();
   registros--;
   return registros;
  	
  }
  
   int tamanoOfertas(){
   	int registros=0;
   string linea;
   ifstream entrada;
   entrada.open("ofertas.txt");
   if (entrada.good()) {
      while(!entrada.eof()){
      getline(entrada, linea);
      if(linea!=" ")
          registros++;
      }
   }
   else{
      cout << "\n*** Error en la apertura del archivo ***\n\n" ;
   }
   entrada.close();
   registros--;
   return registros;
   	
   }
  
  void LeerOfertantes(){
  	string linea;
    ifstream entrada;
   entrada.open("ofertantes.txt");
   if (entrada.good()){
      for(int i=0; i<cantidad_ofertantes;  i++){

         getline(entrada, linea,';');
         ofertantes[i].nombre = linea;

         getline(entrada, linea,';');
         ofertantes[i].cedula = linea;

         getline(entrada, linea,';');
         ofertantes[i].correo = linea;
         
         getline(entrada, linea,';');
         ofertantes[i].telefono = linea;
         
         getline(entrada, linea,';');
         ofertantes[i].id_telefono = linea;
         
         getline(entrada, linea,';');
         ofertantes[i].oferta = atoi(linea.c_str());
         
         getline(entrada, linea,'\n');
         ofertantes[i].deposito = atoi(linea.c_str());
      }
   }
   else{
       cout << "\n*** Error en la apertura del archivo ***\n\n" ;
       exit(1);     //termina la ejecución.

   }
   entrada.close();
  	
  }
  
  void LeerCelulares(){
  	string linea;
    ifstream entrada;
   entrada.open("celulares.txt");
   if (entrada.good()){
      for(int i=0; i<cantidad_celulares;  i++){
      	
         getline(entrada, linea,';');
         celulares[i].id = linea;

         getline(entrada, linea,';');
         celulares[i].marca = linea;

         getline(entrada, linea,';');
         celulares[i].modelo = linea;

         getline(entrada, linea,';');
         celulares[i].gama = linea;
         
         getline(entrada, linea,'\n');
         celulares[i].costo_base = atoi(linea.c_str());
         
        
      }
   }
   else{
       cout << "\n*** Error en la apertura del archivo ***\n\n" ;
       exit(1);     //termina la ejecución.

   }
   entrada.close();
  	
  }
  
  void LeerOfertas(){
  	string linea;
    ifstream entrada;
   entrada.open("ofertas.txt");
   if (entrada.good()){
      for(int i=0; i<cantidad_ofertas;  i++){

         getline(entrada, linea,';');
         ofertas[i].cedula = linea;

         getline(entrada, linea,'\n');
         ofertas[i].tipo_oferta = atoi(linea.c_str());     
        
      }
   }
   else{
       cout << "\n*** Error en la apertura del archivo ***\n\n" ;
       exit(1);     //termina la ejecución.

   }
   entrada.close();
  	
  }
  
  void RegistrarOfertante(){
  	string  correo,nombre,relefono;
  	int deposito= 0;
  	 if (cantidad_ofertantes == 1000){
  	 	cout<<"la capacidad de ofertantes a sido alcanzada "<<endl<<endl;
  	 	getch();
	}else{
		cin.ignore();
		cout << "\n\nAGREGANDO UN OFERTANTE:\n\n";
		cout<<"----------------------------------"<<endl;
		cout<<"Digite el nombre del ofertante: ";
		getline(cin, ofertantes[cantidad_ofertantes].nombre);
		cout<<"Digite la cedula del ofertante: ";
		getline(cin, ofertantes[cantidad_ofertantes].cedula);
     	cout << "digite el correo electronico: " ;
        getline(cin, ofertantes[cantidad_ofertantes].correo);
     	cout << "digite el celular: " ;
        getline(cin, ofertantes[cantidad_ofertantes].telefono);
       // cout << "digite el deposito : " ;
        //cin>>ofertantes[cantidad_ofertantes].deposito;
        ofertantes[cantidad_ofertantes].id_telefono = " ";
        ofertantes[cantidad_ofertantes].deposito= 0;
        ofertantes[cantidad_ofertantes].oferta =0;
        cout << "\n\n\nEl ofertante ha sido agregado " << endl << endl;
         cantidad_ofertantes++;
      getch();
	}
	GuardarOfertantes();
   }
	
	void RegistrarCelular(){
		string marca,modelo,gama;
		int costo_base;
		if(cantidad_celulares== 100){
			cout<<"la capacidad de celulares a sido alcanzada "<<endl<<endl;
			getch();
		}else{
			cin.ignore();
			cout << "\n\nAGREGANDO UN CELULAR:\n\n";
			cout<<"----------------------------------"<<endl;
			cout<<"Digite el id del celular: ";
			getline(cin, celulares[cantidad_celulares].id);
			cout<<"Digite la marca del celular: ";
			getline(cin, celulares[cantidad_celulares].marca);
			cout<<"Digite el modelo del celular: ";
			getline(cin, celulares[cantidad_celulares].modelo);
			cout<<"Digite la gama del celular: ";
			getline(cin, celulares[cantidad_celulares].gama);
			cout<<"<Digite el costo base del celular: ";
			cin>>celulares[cantidad_celulares].costo_base;
			cout << "\n\n\nEl celular ha sido agregado " << endl << endl;
			cantidad_celulares++;
			getch();
			
		}		
		GuardarCelulares();
	}
	
	void RegistrarOferta(){
		
		string cedula,id_telefono_ofertar;
		int tipo,incremento_abierta;
		bool salir1=false , salir2=false;
		if(cantidad_celulares == 1000){
			cout<<"la capacidad de ofertas a sido alcanzada "<<endl<<endl;
			
		}else{
			cin.ignore();
			cout << "\n\nAGREGANDO UNA OFERTA:\n\n";
			cout<<"----------------------------------"<<endl;
			cout<<"Digite la  cedula del ofertante: ";
			getline(cin,cedula);
			if( BuscarOfertante(cedula) >= 0){
				cout<<"BIENBENID@ "<<ofertantes[BuscarOfertante(cedula)].nombre<<endl;
				ofertas[cantidad_ofertas].cedula = cedula;
                do
                {
				cout<<"\nDigite el tipo de oferta [1]minima [2]moderada [3]abierta : ";
				cin>>tipo;
		     	
		     	switch(tipo){
		     		case 1:
		     			system("cls");
							cout << "oferta minima.\n";
							ofertas[cantidad_ofertas].tipo_oferta= tipo;
							cantidad_ofertas++;
							
							
							while(true){
								cin.ignore();
								cout << "\n Digite el id del telefono al que desea ofertar :";
								getline(cin,id_telefono_ofertar);

								if(BuscarCelular(id_telefono_ofertar) >=0 ){
									if(celulares[BuscarCelular(id_telefono_ofertar)].gama == "alta"){
										ofertantes[BuscarOfertante(cedula)].deposito = (60000+celulares[BuscarCelular(id_telefono_ofertar)].costo_base)*0.30;
										ofertantes[BuscarOfertante(cedula)].oferta = 60000+celulares[BuscarCelular(id_telefono_ofertar)].costo_base;
										cout<<"su oferta es de -->"<<ofertantes[BuscarOfertante(cedula)].oferta<<endl;
										cout<<"su deposito es de -->"<<ofertantes[BuscarOfertante(cedula)].deposito<<endl;
										system("pause");
										break;
									}
									if(celulares[BuscarCelular(id_telefono_ofertar)].gama== "media"){
										ofertantes[BuscarOfertante(cedula)].deposito = (40000+celulares[BuscarCelular(id_telefono_ofertar)].costo_base)*0.30;
										ofertantes[BuscarOfertante(cedula)].oferta = 40000+celulares[BuscarCelular(id_telefono_ofertar)].costo_base;
										cout<<"su oferta es de -->"<<ofertantes[BuscarOfertante(cedula)].oferta<<endl;
										cout<<"su deposito es de -->"<<ofertantes[BuscarOfertante(cedula)].deposito<<endl;
										system("pause");
										break;
									}
									if(celulares[BuscarCelular(id_telefono_ofertar)].gama== "baja"){
										ofertantes[BuscarOfertante(cedula)].deposito = (20000+celulares[BuscarCelular(id_telefono_ofertar)].costo_base)*0.30;
										ofertantes[BuscarOfertante(cedula)].oferta = 20000+celulares[BuscarCelular(id_telefono_ofertar)].costo_base;
										cout<<"su oferta es de -->"<<ofertantes[BuscarOfertante(cedula)].oferta<<endl;
										cout<<"su deposito es de -->"<<ofertantes[BuscarOfertante(cedula)].deposito<<endl;
										system("pause");
										break;
									}
									
										
							}else{
								
								cout<<"\nCelular no encontrado  digite nuevamente\n ";
								system("pause");
							}
							}
							
							salir1 = true;
							break;
		     		case 2:
		     				system("cls");
							cout << "oferta moderada.\n";
							ofertas[cantidad_ofertas].tipo_oferta= tipo;
							cantidad_ofertas++;
	
							
							while(true){
								cin.ignore();
								cout << "\n Digite el id del telefono al que desea ofertar :";
								getline(cin,id_telefono_ofertar);
								if(BuscarCelular(id_telefono_ofertar) >= 0 ){
									if(celulares[BuscarCelular(id_telefono_ofertar)].gama == "alta"){
										ofertantes[BuscarOfertante(cedula)].deposito = (80000+celulares[BuscarCelular(id_telefono_ofertar)].costo_base)*0.30;
										ofertantes[BuscarOfertante(cedula)].oferta = 80000+celulares[BuscarCelular(id_telefono_ofertar)].costo_base;
										cout<<"su oferta es de -->"<<ofertantes[BuscarOfertante(cedula)].oferta<<endl;
										cout<<"su deposito es de -->"<<ofertantes[BuscarOfertante(cedula)].deposito<<endl;
										break;
										system("pause");
									}
									if(celulares[BuscarCelular(id_telefono_ofertar)].gama== "media"){
										ofertantes[BuscarOfertante(cedula)].deposito = (60000+celulares[BuscarCelular(id_telefono_ofertar)].costo_base)*0.30;
										ofertantes[BuscarOfertante(cedula)].oferta = 60000+celulares[BuscarCelular(id_telefono_ofertar)].costo_base;
										cout<<"su oferta es de -->"<<ofertantes[BuscarOfertante(cedula)].oferta<<endl;
										cout<<"su deposito es de -->"<<ofertantes[BuscarOfertante(cedula)].deposito<<endl;
										system("pause");
										break;
									}
									if(celulares[BuscarCelular(id_telefono_ofertar)].gama== "baja"){
										ofertantes[BuscarOfertante(cedula)].deposito = (40000+celulares[BuscarCelular(id_telefono_ofertar)].costo_base)*0.30;
										ofertantes[BuscarOfertante(cedula)].oferta = 40000+celulares[BuscarCelular(id_telefono_ofertar)].costo_base;
										cout<<"su oferta es de -->"<<ofertantes[BuscarOfertante(cedula)].oferta<<endl;
										cout<<"su deposito es de -->"<<ofertantes[BuscarOfertante(cedula)].deposito<<endl;
										system("pause");
										break;
										
									}
									
										
							}else{
								
								cout<<"\nCelular no encontrado  digite nuevamente\n ";
								system("pause");
							}
							}
							salir1 = true;
							getch();
							break;
		     		case 3:
		     			system("cls");
							cout << "oferta abierta.\n";
							ofertas[cantidad_ofertas].tipo_oferta= tipo;
							cantidad_ofertas++;
							
							while(true){
								cin.ignore();
								cout << "\n Digite el id del telefono al que desea ofertar :";
								getline(cin,id_telefono_ofertar);
								if(BuscarCelular(id_telefono_ofertar) >= 0 ){
										cout<<"Digite el  valor que desea incrementar el costo base del telefono : ";
										cin>>incremento_abierta;				
										ofertantes[BuscarOfertante(cedula)].deposito =(incremento_abierta +	celulares[BuscarCelular(id_telefono_ofertar)].costo_base)*0.3;
										ofertantes[BuscarOfertante(cedula)].oferta = incremento_abierta+celulares[BuscarCelular(id_telefono_ofertar)].costo_base;
										cout<<"su oferta es de -->"<<ofertantes[BuscarOfertante(cedula)].oferta<<endl;
										cout<<"su deposito es de -->"<<ofertantes[BuscarOfertante(cedula)].deposito<<endl;
									break;	
							}else{
								
								cout<<"\nCelular no encontrado  digite nuevamente\n ";
								system("pause");
							}
							}
							
							salir1 = true;
							getch();
							break;
		     		default:
		     			salir1= false;
		     			cout<<"opcion invalida";
		     			break;
		     		
				 }
				}while(salir1!=true);
				
			}else {
				cout<<"\n no se pudo realizar el registro de oferta";
				system("pause");
			}
			
		/*	cout<<"Digite el tipo de oferta [1]minima [2]moderada [3]abierta : ";
			cin>>ofertas[cantidad_ofertas].tipo_oferta;
		    cout << "\n\n\nLa oferta ha sido agregado " << endl << endl;
			cantidad_ofertas++;
			getch();*/
			
		}		
		GuardarOfertas();
		GuardarOfertantes();
	}
	
	
	void GuardarOfertantes(){
		ofstream salida;
		salida.open("ofertantes.txt",ios::out);
		if(salida.good() ){
			for(int i =0; i<=cantidad_ofertantes ; i++){
				if(ofertantes[i].nombre!= " "){
					salida<<ofertantes[i].nombre<<";"<<ofertantes[i].cedula<<";"<<ofertantes[i].correo<<";"<<ofertantes[i].telefono<<";"<<ofertantes[i].id_telefono<<";"<<ofertantes[i].oferta<<";"<<ofertantes[i].deposito<<endl;
				}
			}
			
		}else{
			cout<<"error al guardar el archivo.los datos no se guardaron"<<endl<<endl;
			getch();
		}
		
		
	}
	
	void GuardarCelulares(){
		ofstream salida;
		salida.open("celulares.txt",ios::out);
		if(salida.good() ){
			for(int i =0; i<=cantidad_celulares ; i++){
				if(celulares[i].marca!= " "){
					salida<<celulares[i].id<<";"<<celulares[i].marca<<";"<<celulares[i].modelo<<";"<<celulares[i].gama<<";"<<celulares[i].costo_base<<endl;
				}
			}
			
		}else{
			cout<<"error al guardar el archivo los datos no se guardaron"<<endl<<endl;
			getch();
		}
	}
	
	void GuardarOfertas(){
		ofstream salida;
		salida.open("ofertas.txt",ios::out);
		if(salida.good() ){
			for(int i =0; i<=cantidad_ofertas ; i++){
				if(ofertas[i].cedula!= " "){
					salida<<ofertas[i].cedula<<";"<<ofertas[i].tipo_oferta<<endl;
				}
			}
			
		}else{
			cout<<"error al guardar el archivo los datos no se guardaron"<<endl<<endl;
			getch();
		}
	}
	
	void InformacionOfertantes(){
		cantidad_ofertantes = tamanoOfertantes();
		LeerOfertantes();

    	 for (int i= 0; i<cantidad_ofertantes ; i++){
      		  if (ofertantes[i].nombre != " " && ofertantes[i].nombre != ""){
			   system("cls");
			   cout << " +----------------------------------------------------------------+" << endl ;
		       cout << " |                    LISTA GENERAL DE OFERTANTES                 |" << endl ;
		       cout << " +----------------------------------------------------------------+" << endl ;
	           cout << "\n\nNombre : " << ofertantes[i].nombre  << endl;
	           cout << "Cedula : " << ofertantes[i].cedula << endl;
	           cout << "Correo : " << ofertantes[i].correo << endl;
	           cout << "Celular : " << ofertantes[i].telefono << endl;//atoi(linea.c_str())
	           cout << "celular por el que oferta : " << celulares[atoi(ofertantes[i].id_telefono.c_str())].marca<<"-"<< celulares[atoi(ofertantes[i].id_telefono.c_str())].modelo << endl;
	           cout << "oferta : " << ofertantes[i].oferta << endl;
	           cout << "Deposito : " << ofertantes[i].deposito << endl;
	           system("pause");
        }
     }
     cout << "\n\n\n              ********   Fin del Listado   ******** " << endl << endl << endl;
     system("pause");
	}
	
	void InformacionCelulares(){
		cantidad_celulares = tamanoCelulares();
		LeerCelulares();
		for (int i= 0; i<cantidad_celulares ; i++){
      		  if (celulares[i].modelo != " " && celulares[i].modelo != ""){
			   system("cls");
			   cout << " +----------------------------------------------------------------+" << endl ;
		       cout << " |                    LISTA GENERAL DE CELULARES                  |" << endl ;
		       cout << " +----------------------------------------------------------------+" << endl ;
		       cout << "\n\nId : " << celulares[i].id  << endl;
	           cout << "\n\nMarca : " << celulares[i].marca  << endl;
	           cout << "Modelo : " << celulares[i].modelo << endl;
	           cout << "Gama : " << celulares[i].gama << endl;
	           cout << "Costo Base : " << celulares[i].costo_base << endl;
	           system("pause");
        }
     }
     cout << "\n\n\n              ********   Fin del Listado   ******** " << endl << endl << endl;
     system("pause");
		
	}
	
	void InformacionOfertas(){
		cantidad_ofertas = tamanoOfertas();
		LeerOfertas();
		for (int i= 0; i<cantidad_ofertas ; i++){
      		  if (ofertas[i].cedula != " " && ofertas[i].cedula != ""){
			   system("cls");
			   cout << " +----------------------------------------------------------------+" << endl ;
		       cout << " |                    LISTA GENERAL DE OFERTAS                    |" << endl ;
		       cout << " +----------------------------------------------------------------+" << endl ;
	           cout << "\n\nCedula : " << ofertas[i].cedula  << endl;
	           cout << "Tipo de oferta : " << ofertas[i].tipo_oferta << endl;
	           system("pause");
        }
     }
     cout << "\n\n\n              ********   Fin del Listado   ******** " << endl << endl << endl;
     system("pause");
		
	}
	
	int BuscarOfertante(string cedula){
		 string linea; 
		   int encontrado=0;
		   for(int k=0; k<cantidad_ofertantes; k++){
		      if(ofertantes[k].cedula == cedula){
		         encontrado=1;
		         return k;

		      }
		   }
		   if(encontrado==0){
		       cout << "\n\n\nNo hay ofertante con ese numero de cedula \n\n";
		       return -1;
		       system("pause");
		   		}
   	}
	
	int BuscarCelular(string id){
           string linea;  
		   int encontrado=0;
		   for(int k=0; k<cantidad_celulares; k++){
		   	
		      if(celulares[k].id == id){
		         encontrado=1;
		         return k;

		      }
		   }
		   if(encontrado==0){
		       cout << "\n\n\nNo  existe telefono con ese identificador \n\n";
		       return -1;
		       system("pause");
		   		}
		}
		
		int BuscarOferta(string cedula){
		
           string linea;
		   cin.ignore();
		   
		   int encontrado=0;
		   for(int k=0; k<cantidad_ofertas; k++){
		      if(ofertas[k].cedula == cedula){
		         encontrado=1;
		         return k;

		      }
		   }
		   if(encontrado==0){
		       cout << "\n\n\nNo existe oferta registrada  de esta persona \n\n";
		       return -1;
		       system("pause");
		   		}
		}
	
	
