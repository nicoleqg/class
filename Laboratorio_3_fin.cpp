#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

using namespace std;

class converter{
	int _resolucion;
	int _canales [32];
	int _can;
	int _frecuencia;
	double _voltaje;
	double vdigital;
	float adc[32];
public:
	converter ( int ,int );
	converter ();
	void leer();
	void imprimir();
};

converter::converter( int resolucion, int frecuencia){
	_resolucion= resolucion;
	_frecuencia= frecuencia;
}

converter::converter(){
	_resolucion=8;
	_frecuencia=0;
}



void converter::leer(){
	int ca;
	int i;
	
	cout<<"Ingrese la resolución (8, 10 o 12 bits): "<<endl;
	cin>> _resolucion;
	cout<<"¿Cuál es la frecuencia?: "<<endl;
	cin>> _frecuencia;	
	cout<<"¿Cuántos canales serán? [Máximo de canales = 32]: "<<endl;
	cin>> _can;
	
	for (i=0;i<33;i++){
    	_canales[i] = 1;
  	}
	
	
	for (i=0; i<=_can; i++){
		cout<<"¿Qué canal vas a usar ("<<i+1<<"): "<<endl;
		cin>> ca;
		_canales[ca]=0; 
		cout<<"¿Cuál es el voltaje de entrada para el canal "<<ca<<"?(max 3.3v):";
		cin>> vdigital;
		adc[ca]=(vdigital*(pow (2,_resolucion)-1))/3.3; 

	}
	}
	

void converter::imprimir(){
	int i;
	cout<<"La resolución para todos los canales es: "<<_resolucion<< " bits"<<endl;
	cout<<"La frecuencia de muestreo para todos los canales es: "<<_frecuencia<< " Hz"<<endl;
	
	for (i=0;  i<33; i++){
		if (_canales[i]==0){
		cout<<"La conversión ADC del canal "<<i<<" es "<<adc[i]<<endl;
		}
	}
	
}
int main() {
setlocale(LC_ALL,"");
converter ADC;
fflush (stdin);
ADC.leer();
ADC.imprimir();
return 0;
		
}
	
