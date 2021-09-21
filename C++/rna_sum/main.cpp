//
//  main.cpp
//  rna_sum
//
//  Created by JAVIER ALEJANDRO RAMIREZ GARCIA on 10/03/15.
//  Copyright (c) 2015 alejo. All rights reserved.
//

#include <iostream>
#include <cstdlib>

class neurona{
    long double x1 = 0 , x2 = 0, x3 = 0, x4 = 0; //Entradas red neuronal
    long double neurona1 = 0, neurona2 = 0, neurona3 = 0; //Neuronas
    long double vi = 0, error = 0, i = 1 , ta = 0.01; // Valor ideal, error, iteraciones y tasa de aprendizaje
    long double wv1 = 0, wv2 = 0, wv3 = 0, wv4 = 0, wv5 = 0, wv6 = 0; // variación de pesos sinapticos
    //long double w11 = rand(), w12 = rand(), w23 = rand(), w24 = rand(), w35 = rand(), w36 = rand(); //pesos sinapticos
    //long double w11 = 1, w12 = 1, w23 = -1, w24 = -1, w35 = 1, w36 = 1; //pesos sinapticos ideales
    long double w11 = 0.9, w12 = 0.9, w23 = -0.9, w24 = -0.9, w35 = 0.9, w36 = 0.9; //pesos sinapticos cercanos al ideal*/
    public: void rna(long double, long double, long double, long double, long double);
    long double cp(){
        while(neurona3 != vi){
            
            //Computo neuronal
            neurona1 = (x1*w11)+(x2*w12);
            neurona2 = (x3*w23)+(x4*w24);
            neurona3 = (neurona1*w35)+(neurona2*w36);
            
            //Algoritmo De Corección de error
            if(neurona3 != vi){
                
                error = vi - neurona3;
                
                //variación de pesos sinapticos
                wv1 = (ta)*(x1)*(error);
                wv2 = (ta)*(x2)*(error);
                wv3 = (ta)*(x3)*(error);
                wv4 = (ta)*(x4)*(error);
                wv5 = (ta)*(neurona1)*(error);
                wv6 = (ta)*(neurona2)*(error);
                
                //nuevos pesos sinapticos
                w11+= wv1;
                w12+= wv2;
                w23+= wv3;
                w24+= wv4;
                w35+= wv5;
                w36+= wv6;
            }
            
            //iteracciones
            std::cout << "iteracción Nº "<<i<<"\n";
            i++;
        }
        
        return neurona3;
    }
};

void neurona::rna(long double v, long double w, long double x, long double y, long double z){
    x1 = v;
    x2 = w;
    x3 = x;
    x4 = y;
    vi = z;
}

int main() {
    long double a = 0, b = 0, c = 0, d = 0; //valores de entrada
    long double ri = 0; //valor ideal
    neurona neurona1; //funcion RNA;
    long double aux1 = 0;
   
    std::cout << "RNA (A+B)-(C+D)\n";
    std::cout << "Integrantes:\n";
    std::cout << "Nelson Liberato\n";
    std::cout << "Javier Ramirezs\n";
    std::cout << "Kevin Zambrano\n";
    std::cout << "Ingrese el valor de a\n";
    std::cin>>a;
    std::cout << "Ingrese el valor de b\n";
    std::cin>>b;
    std::cout << "Ingrese el valor de c\n";
    std::cin>>c;
    std::cout << "Ingrese el valor de d\n";
    std::cin>>d;
    ri = (a+b)-(c+d);
    std::cout << "La salida ideal es de "<<ri<<"\n";
    
    neurona1.rna(a, b, c, d, ri);
    aux1 = neurona1.cp();
    std::cout << "El computo neuronal es "<<aux1<<" la red neuronal aprendio\n";

    return 0;
}
