//
//  main.cpp
//  rna_salto
//
//  Created by JAVIER ALEJANDRO RAMIREZ GARCIA on 10/03/15.
//  Copyright (c) 2015 alejo. All rights reserved.
//

#include <iostream>
#include <cstdlib>

class neurona{
    int x1, x2, w1 , w2, si = 0, neurona1 = 0, error = 1, wv1 = 0, wv2 = 0, i=1, aux1 = 0, aux2 = 0;
    public: void rna(int, int);
    int cp(){
        aux1 = 0;
        aux2 = 0;
        i = 1;
        w1 = rand();
        w2 = rand();
        while(aux2 != 1){
            
            //Salida ideal compuerta OR
            if(x1==0 && x2==0){
                si = 0;
            }else{
                si = 1;
            }
            
            //Computo neuronal
            neurona1 = (x1*w1)+(x2*w2);
            
            if(neurona1 <= 0){
                aux1 = 0;
            }else{
                aux1 = 1;
            }
            
            error = si - neurona1;
            
            //algoritmo de corrección de error
            if(error != 0){
                wv1 = (1)*(error)*(x1);
                wv2 = (1)*(error)*(x2);
                w1+= wv1;
                w2+= wv2;
            }else{
                aux2 = 1;
            }
            
            //iteracciones
            std::cout << "iteracción Nº "<<i<<"\n";
            i++;
        }
        
        return aux1;
    }
};

void neurona::rna(int x, int y){
    x1 = x;
    x2 = y;
}

int main() {
    
    std::cout << "RNA Salto de Obstaculo\n";
    std::cout << "Integrantes:\n";
    std::cout << "Luis Felipe Hernandez\n";
    std::cout << "Javier Alejandro Ramirez Garcia\n";
    
    int escenario [] = {0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1};
    int i = 0, aux = 0, longitud = 0;
    neurona neurona1;
    
    longitud =  (sizeof escenario / sizeof *escenario)-1;
    
    for(i=0;i<=longitud;i++){
        if(escenario[i+1]!=0 || escenario[i+1]!=1){
            neurona1.rna(escenario[i],0);
        }else{
            neurona1.rna(escenario[i],escenario[i+1]);
        }
        
        aux = neurona1.cp();
        
        if(aux==1){
            std::cout <<"Salto obstaculo\n";
        }else{
            std::cout <<"Sigo caminando\n";
        }
        
    }
    
    
    
    return 0;
}
