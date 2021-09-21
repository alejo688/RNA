//
//  main.cpp
//  rna_and
//
//  Created by JAVIER ALEJANDRO RAMIREZ GARCIA on 17/03/15.
//  Copyright (c) 2015 alejo. All rights reserved.
//

#include <iostream>
#include <cstdlib>

class neurona{
    int x1, x2, w1 = 1, w2 = 1, si, neurona1, error, wv1, wv2, i, aux1, aux2;
    public: void rna(int, int);
    int cp(){
        aux1 = 0;
        aux2 = 0;
        i = 1;
        error = 0;
        wv1 = 0;
        wv2 = 0;
        i = 1;
        /*w1 = rand() % -100 + 100;
        w2 = rand() % -100 + 100;
        while(aux2 != 1){*/
            neurona1 = (x1*w1)+(x2*w2);
            /*if(x1==1 && x2==1){
                si = 1;
            }else{
                si = 0;
            }*/
            if(neurona1 > 0){
                aux1 = 1;
            }else{
                aux1 = 0;
            }
            /*if(aux1 != si){
                error = si - neurona1;
                wv1 = (1)*(error)*(x1);
                wv2 = (1)*(error)*(x2);
                w1+= wv1;
                w2+= wv2;
                std::cout << "iteracción Nº "<<i<<"\n";
            }else{
                std::cout << "La red neuronal aprendio para "<<x1<<"-"<<x2<<" = "<<aux1<<"\n";
                aux2 = 1;
            }
            i++;
        }*/
        
        return aux1;
    }
};

void neurona::rna(int x, int y){
    x1 = x;
    x2 = y;
}

int main() {
    
    std::cout << "RNA And\n";
    std::cout << "Integrantes:\n";
    std::cout << "Luis Felipe Hernandez\n";
    std::cout << "Javier Alejandro Ramirez Garcia\n";
    
    int a [] = {1,1,0,0};
    int b [] = {1,0,1,0};
    int j = 0;
    neurona neurona1;
    
    for(j=0;j<=3;j++){
        neurona1.rna(a[j],b[j]);
        //neurona1.cp();
        if(a[j]==1 && b[j]==1){
            if(neurona1.cp() == 1){
                std::cout << "La red neuronal aprendio para "<<a[j]<<"-"<<b[j]<<"\n";
            }else{
                std::cout << "La red neuronal no aprendio para "<<a[j]<<"-"<<b[j]<<"\n";
            }
        }else{
            if(neurona1.cp() == 0){
                std::cout << "La red neuronal aprendio para "<<a[j]<<"-"<<b[j]<<"\n";
            }else{
                std::cout << "La red neuronal no aprendio para "<<a[j]<<"-"<<b[j]<<"\n";
            }
        }

    }
    
    return 0;
}

