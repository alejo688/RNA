/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package xor;

/**
 *
 * @author JavierAlejandro
 */
public class RNA {
    
    public void computo(double x1, double x2, double w1, double w2, double bi){
        double si, neurona = -1, j = 1, error, wn1, wn2, ta = 0.001;
        
        System.out.print("Computo neuronal para el caso "+x1+" "+x2+"\n");
        
        if(x1 == x2){
            si = 0;
        }else{
            si = 1;
        }
        
        System.out.print("Salida ideal: "+si+"\n");
        
        while(neurona != si){
            neurona = (x1*w1) + (x1*w2) + bi;
            System.out.print(neurona+" Iteración "+j+"\n");
            error = neurona - si;
            if(error != 0){
                wn1 = ta*error*x1;
                w1 += wn1;
                wn2 = ta*error*x2;
                w2 += wn2;
            }
            
            j++;
        }
    }
}
