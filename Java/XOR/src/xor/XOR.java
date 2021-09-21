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

import xor.RNA;

public class XOR {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args){
        
       double w11 = 5, w12 = 0;
       double bi = -0.1;
       double[] x1 = {1,1,0,0};
       double[] x2 = {1,0,1,0};
       int i;
       
       RNA rna = new RNA();
       
       System.out.print("Computo neuronal para la Compuerta XOR con reinicio de peso sinapticos.\n");
       for(i=0;i<=3;i++){
           //System.out.print(x1[i]+"-"+x2[i]+"\n");
           rna.computo(x1[i], x2[i], w11, w12, bi);
       } 
    }
    
}
