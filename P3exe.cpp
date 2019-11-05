#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <sstream>
#include <math.h>  
#include <iomanip>      
using namespace std;

void tomarAyB();
float fde(float num);
void takeCoeficientes();
void showEquation();
float A=0,B=0,Xr=0,fa=0,fb=0,faXfxr=0,aMinusb=0;
float cx0=0,cx1=0,cx2=0,cx3=0, cx4=0, cx5=0;
void printClosed();
float absolute (float number);
std::string Convert (float number);

int main() {
		int menu,menu2,menu3,menu4;



do {
	cout<<"\t\tMenu 1"<<endl<<endl;
	cout<<"1.Hoja de Presentacion"<<endl;
	cout<<"2.Insercion de funcion polinomica"<<endl;
	cout<<"3.Metodo cerrado"<<endl;
	cout<<"4.Metodo abierto"<<endl;
	cout<<"5.Salir del programa"<<endl<<endl;
	cout<<"Eliga la opcion que desea:"<<endl;
	cin>>menu;
	system("cls");
		switch(menu){
			case 1:
					cout<<"\tUNIVERSIDAD TECNOLOGICA DE PANAMA"<<endl;
					cout<<"\tFACULTAD DE SISTEMAS Y COMPUTACION"<<endl;
					cout<<"LICENCIATURA EN INGENIERIA EN SISTEMAS COMPUTACIONALES"<<endl;
					cout<<"\tMETODOS NUMERICOS PARA INGENIEROS"<<endl;
					cout<<"\t\tPROYECTO N2"<<endl;
					cout<<"\t\t   TEMA:"<<endl;
					cout<<"SISTEMAS DE ECUACIONES ALGEBRAICAS LINEALES"<<endl;
					cout<<"FACILITADOR: ING.JACQUELINE S. DE CHING"<<endl;
					cout<<"\t\tINTEGRANTES:"<<endl;
					cout<<"\t EDGAR MARTIN 8-913-1957"<<endl;
					cout<<"\t IVES DE LA CRUZ 6-720-1526"<<endl;
					cout<<"\t\t 1IL-124"<<endl;
					cout<<"\t\t 20/10/19"<<endl;
					system("pause");
					system("cls");
			break;
			case 2:
				cout<<"Insercion de coeficientes"<<endl;
			//	tomarAyB();
				takeCoeficientes();
				
				showEquation();
				system("pause");
				system("cls");	
			break;
			
			case 3:
				cout<<"Metodo cerrado"<<endl;
				tomarAyB();
				printClosed();
				
				cout << endl;
			//	cout<<"f(a)="<<fde(A)<<endl;
			//	cout<<"f(b)="<<fde(B)<<endl;
			//	cout<<"f(Xr)="<<fde((A+B)/2)<<endl;
				
				
				system("pause");
				system("cls");	
			break;
		
			case 4:
				cout<<"Metodo abierto"<<endl;
				system("pause");
				system("cls");	
			break;
		
		}

	}while(menu!=5);

}

void tomarAyB(){
	cout<<"Inserte A: ";
	cin>>A;
	cout <<"inserte B: ";
	cin>>B;
	
	}
	
void takeCoeficientes(){
	
	cout<<"Coeficiente de x^5: ";
	cin>>cx5;
	cout<<"Coeficiente de x^4: ";
	cin>>cx4;
	cout<<"Coeficiente de x^3: ";
	cin>>cx3;
	cout<<"Coeficiente de x^2: ";
	cin>>cx2;
	cout<<"Coeficiente de x^1: ";
	cin>>cx1;
	cout<<"Coeficiente de x^0: ";
	cin>>cx0;
	
	
}

void showEquation(){
	
	  std::cout <<Convert(cx5)<<"(x^5)"<<Convert(cx4)<<"(x^4)"<< Convert(cx3)<<"(x^3)"<< Convert(cx2)<< "(x^2)" << Convert(cx1)<< "(x)" << Convert(cx0)<< ""<<'\n';
}

std::string Convert (float number){
    std::ostringstream buff;
    string numero;
    buff<<number;
     numero = buff.str();
    if (number>0 || number==0){
    numero = "+" + buff.str();
		} 
		
    return numero;   
}

float fde(float num){
	
	float result;
	
	result = cx5*pow (num,5)+cx4*pow (num,4)+cx3*pow (num,3)+cx2*pow (num,2)+cx1*pow (num,1)+cx0*pow (num,0);
	
	return result;
	
}

void printClosed(){
	 std::cout <<"| Ite "<<"|  A "<< "| B  "<< "| Xr   "<< "| f(a) " << "| f(b) "<< "| f(Xr) "<<"|f(a)*f(Xr)| "<<" |a-b| " << "|ERAP";
	 cout <<endl;
	 
	 for (int i=0;i<=3;i++){
	 	
	 	Xr=(A+B)/2;
	 	
	 	
	 	std::cout <<"| " << i;
		 cout <<"   |  "<< A;
		 cout <<" |  "<< B;
		 cout <<" |  "<< Xr;
		 cout <<" |   "<<fde(A); 
		 cout <<"  |   "<< fde(B);
		  cout << "  |  "<< fde(Xr);
		  cout <<"    |    "<< fde(A)*fde(Xr);
		  cout <<"     |   "<< absolute(A-B);
		  cout << "   | ERAP";
	 	
	 	cout <<endl;
	 	
	 }
	
}

float absolute (float number){
	
	if (number <0){
		number=number *-1;
	}
	return number;
	
}










