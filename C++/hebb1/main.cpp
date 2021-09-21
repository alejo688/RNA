//
//  main.cpp
//  hebb1
//
//  Created by JAVIER ALEJANDRO RAMIREZ GARCIA on 21/04/15.
//  Copyright (c) 2015 alejo. All rights reserved.
//

#include <iostream>
#include <cstdlib>

class neurona{
    float x1, neurona1 = 0, aux1 = 0, i, wv1, sig1, sig2;
    //float w11 = rand();
    float w11 = -0.5; //peso sinaptico
    public: void rna(float);
    int cp(){
        for(i = 0; i<=1000; i++){
            /*computo neuronal*/
            neurona1 = (x1*w11);
            if (neurona1 >= 0) {
                aux1 = 1;
            }else{
                aux1 = -1;
            }
            
            /*Determinar los signos de la entrada y salida*/
            if(x1>=0){
                sig1 = 1;
            }else{
                sig1 = -1;
            }
            
            if(aux1>=0){
                sig2 = 1;
            }else{
                sig2 = -1;
            }
            
            /*Estados*/
            
            if(sig1 != sig2){
                std::cout << "Inactivo \n";
            }else{
                std::cout << "Activo \n";
            }
            
            /*Algoritmo de heb*/
            if(sig1 != sig2){
                std::cout << "Ejecuto heb \n";
                wv1 = (-1)*(x1)*aux1;
                w11 += wv1;
            }
            
        }
        
        return neurona1;
    }
};

void neurona::rna(float x){
    x1 = x;
}

int main() {
    float a = 0, aux = 0;
    neurona neurona1;
    
    std::cout << "RNA Hebb\n";
    std::cout << "Integrantes:\n";
    std::cout << "Luis Felipe Hernandez\n";
    std::cout << "Javier Alejandro Ramirez Garcia\n";
    std::cout << "Luis Rojas\n";
    std::cout << "Ingrese el valor de la entrada\n";
    std::cin>>a;
    
    neurona1.rna(a);
    aux = neurona1.cp();
    
    return 0;
    
}

