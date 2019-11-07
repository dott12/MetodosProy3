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
float closed [99][10];
void doClosed();
void testvalues();
double erap;

int main() {
		int menu,menu2,menu3,menu4;



do {
	cout<<"\t\tMenu 1"<<endl<<endl;
	cout<<"1.Hoja de Presentacion"<<endl;
	cout<<"2.Insercion de funcion polinomica"<<endl;
	cout<<"3.Metodo cerrado"<<endl;
	cout<<"4.Metodo abierto"<<endl;
	cout<<"5.Salir del programa"<<endl<<endl;
	cout<<"Elija la opcion que desea:"<<endl;
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
				//testvalues();
				showEquation();
				system("pause");
				system("cls");	
			break;
			
			case 3:
				cout<<"Metodo cerrado"<<endl;
				tomarAyB();
				
				//testvalues();
				
				doClosed();
				printClosed();
				
				cout << endl;
			
				
				
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

void doClosed(){
	
	
	
	int j=1;
	
		Xr=(A+B)/2;
		
	
	 closed [0][0]=0;
	 closed [0][1]=A;
	 closed [0][2]=B;
	 closed [0][3]=Xr;
	 closed [0][4]=fde(A);
	 closed [0][5]=fde(B);
	 closed [0][6]=fde(Xr);
	 closed [0][7]=fde(A)*fde(Xr);
	 closed [0][8]=absolute(A-B);
	 closed [0][9]=100.00;
	 
	 do {
	 	
	 	if(closed[j-1][7]>0){
	 		A=closed[j-1][3];
		 }else {
		 	A=closed[j-1][1];
		 }
		 
		 if(closed[j-1][7]<0){
	 		B=closed[j-1][3];
		 }else {
		 	B=closed[j-1][2];
		 }
		 
		 
	 	Xr=(A+B)/2;
	 
	  closed [j][0]=j;
	 closed [j][1]=A;
	 closed [j][2]=B;
	 closed [j][3]=Xr;
	 closed [j][4]=fde(A);
	 closed [j][5]=fde(B);
	 closed [j][6]=fde(Xr);
	 closed [j][7]=fde(A)*fde(Xr);
	 closed [j][8]=absolute(A-B);
	 closed [j][9]=absolute((closed [j][3]-closed [j-1][3])/closed[j][3]);
	 
	 
	 
	 
	 
	 
	 /*if (j==7){
		
		closed [j][9]=0.00;
	}*/
	erap=closed [j][9];
	j++;
	
	
	 } while (erap>=0.0001);
	
	
	
	
}

void printClosed(){
	 std::cout <<"|  Ite "<<"   |   A "<< "    |    B  "<< "  |    Xr   "<< " |    f(a) " << "  |    f(b) "<< "  |    f(Xr)  ";
	 std::cout <<" |  f(a)*f(Xr)   | "<<"  |a-b|  " << "  |  ERAP   |";
	 cout <<endl;
	 bool salir=false;
	 int c=0;
	 
	 /*
	 do{
	 	
	 	std::cout <<"| " << closed [c][0];
		 cout <<"   |  "<< closed [c][1];
		 cout <<" |  "<< closed [c][2];
		 cout <<" |  "<< closed [c][3];
		 cout <<"  |   "<<closed [c][4]; 
		 cout <<"  |   "<< closed [c][5];
		  cout << "  |  "<< closed [c][6];
		  cout <<"    |    "<< closed [c][7];
		  cout <<"     |   "<< closed [c][8];
		  cout << "   | "<<closed [c][9];
	 	cout <<endl;
	 	
	 	c = c+1;
	 	
	 	if (closed[c-1][9]==0){
	 		salir=true;
		 }
	 	
	 } while (salir==false);
	 */
	 
	 
	 while (salir == false) {
	 	
	 	cout<<"| ";
	 	
	 	 std::cout<< fixed << std::setprecision(4)<<closed [c][0];
	 	//std::cout <<"| " << closed [c][0];
	 	
		cout<<"  |  "<< closed [c][1];
		 cout <<" |  "<< closed [c][2];
		 cout <<" |  "<< closed [c][3];
		 cout <<"  |   "<<closed [c][4]; 
		 cout <<"  |   "<< closed [c][5];
		  cout << "  |  "<< closed [c][6];
		  cout <<"    |    "<< closed [c][7];
		  cout <<"     |   "<< closed [c][8];
		  std::cout << "   | ";
		  std::cout<< fixed << std::setprecision(4)<<closed [c][9];
		  cout<<" | ";
	 	cout <<endl;
	 	
	 	c = c+1;
	 	
	 	if (closed[c-1][9]==0){
	 		salir=true;
		 }
	 	
	 	
	 }
	  
	
}

float absolute (float number){
	
	if (number <0){
		number=number *-1;
	}
	return number;
	
}

void testvalues(){
	
/*
	cx5=0;
	cx4=0;
	cx3=1;
	cx2=1;
	cx1=-3;
	cx0=-3;
	*/
	
	cx5=0;
	cx4=0;
	cx3=0;
	cx2=1;
	cx1=0;
	cx0=-0.5;
	
}










