/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cola.trafico;

/**
 *
 * @author ALEJO688
 */
public class hebb {
    
    public double[] red(double x1, double w1){
        double neurona1, aux1, wv1, sig1, sig2, desvio;
        
        /*computo neuronal*/
        neurona1 = (x1*w1);
        if (neurona1 >= 0.5) {
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
            desvio = 1;
            //System.out.print("Desvio \n");
        }else{
            desvio = 0;
            //System.out.print("debe seguir por la misma ruta \n");
        }
            
        /*Algoritmo de heb*/
        if(sig1 != sig2){
            wv1 = (1)*(x1)*aux1;
            w1 += wv1;
        }
        
        double[] resultado = {aux1, w1, desvio};
        
        return resultado;
    }
}
