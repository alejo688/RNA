//
//  main.cpp
//  hebb
//
//  Created by JAVIER ALEJANDRO RAMIREZ GARCIA on 14/04/15.
//  Copyright (c) 2015 alejo. All rights reserved.
//

#include <iostream>
#include <cstdlib>

class neurona{
    int x1, x2, neurona1 = 0, neurona2 = 0, neurona3 = 0, aux1 = 0, aux2 = 0, aux3=0, i, wv1, wv2, wv3, wv4, sig1, sig2, sig3;
    int w11 = rand(), w12 = rand(), w23 = rand(), w34 = rand();
    public: void rna(int, int);
    int cp(){
        for(i = 0; i<=10; i++){
            neurona1 = (x1*w11)+(x2*w12);
            if (neurona1>0) {
                aux1 = 1;
            }else{
                aux1 = 0;
            }
            if(x1>=0){
                sig1 = 1;
            }else{
                sig1 = -1;
            }
            
            if(x2>=0){
                sig2 = 1;
            }else{
                sig2 = -1;
            }
            
            if(aux1>=0){
                sig3 = 1;
            }else{
                sig3 = -1;
            }
            
            if(sig1 != sig3){
                wv1 = (1)*aux1*(x1);
                w11+= wv1;
            }
            
            if(sig2 != sig3){
                wv2 = (1)*aux1*(x2);
                w12+= wv2;
            }

            neurona2 = aux1*w23;
            if (neurona2>0) {
                aux2 = 1;
            }else{
                aux2 = 0;
            }
            
            if(aux2>=0){
                sig1 = 1;
            }else{
                sig1 = -1;
            }
            
            if(sig1 != sig3){
                wv3 = (1)*aux2*aux1;
                w23+= wv3;
            }
            
            neurona3 = aux1*w34;
            if (neurona3>0) {
                aux3 = 1;
            }else{
                aux3 = 0;
            }
            
            if(aux3>=0){
                sig1 = 1;
            }else{
                sig1 = -1;
            }
            
            if(sig1 != sig3){
                wv4 = (1)*aux3*aux1;
                w34+= wv4;
            }
            
            if(aux2 == 1 && aux3 == 1){
                std::cout << "Activo\n";
            }else{
                if(aux2 == -1 && aux3 == -1){
                    std::cout << "Inactivo\n";
                }else{
                    std::cout << "Pausado\n";
                }
            }
        }
        
        return neurona3;
    }
};

void neurona::rna(int x, int y){
    x1 = x;
    x2 = y;
}

int main() {
    int a = 0, b = 0, aux = 0;
    neurona neurona1;
    
    std::cout << "RNA Hebb\n";
    std::cout << "Integrantes:\n";
    std::cout << "Luis Felipe Hernandez\n";
    std::cout << "Javier Alejandro Ramirez Garcia\n";
    std::cout << "Luis Rojas\n";
    std::cout << "Ingrese el valor de la primera entrada\n";
    std::cin>>a;
    std::cout << "Ingrese el valor de la segunda entrada\n";
    std::cin>>b;
    
    neurona1.rna(a, b);
    aux = neurona1.cp();
    
    return 0;
    
}
