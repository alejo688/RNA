/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cola.trafico;

import java.util.LinkedList;
import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;

/**
 *
 * @author alejo688
 */
public class Interfaz extends javax.swing.JFrame {

    /**
     * Creates new form Interfaz
     */
    public Interfaz() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTextArea1 = new javax.swing.JTextArea();
        jButton1 = new javax.swing.JButton();
        jLabel2 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel1.setFont(new java.awt.Font("Lucida Grande", 1, 18)); // NOI18N
        jLabel1.setText("Simulación de desvio vehicular");

        jTextArea1.setColumns(20);
        jTextArea1.setRows(5);
        jScrollPane1.setViewportView(jTextArea1);

        jButton1.setText("Iniciar");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jLabel2.setText("Avenida Boyacá - Avenida de las americas");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(21, 21, 21)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addContainerGap(412, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(jButton1)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(jScrollPane1, javax.swing.GroupLayout.Alignment.TRAILING)
                                .addGroup(layout.createSequentialGroup()
                                    .addComponent(jLabel2)
                                    .addGap(0, 0, Short.MAX_VALUE))))
                        .addGap(22, 22, 22))))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(9, 9, 9)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jLabel2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 204, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addComponent(jButton1)
                .addGap(15, 15, 15))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        
        Random automovil = new Random();
        Timer simulacion = new Timer();
        LinkedList av_boyaca = new LinkedList();
        LinkedList americas = new LinkedList();
        
        TimerTask task;
        task = new TimerTask(){
            
            int  min = 0, j = 0, i = 0, desviar_americas = -1, desviar_boyaca = -1;
            double  volumen_boyaca = 0, volumen_americas = 0, autos_boyaca = 0, autos_americas = 0, w11 = 1, w12 = 1;
            double[] array_boyaca;
            double[] array_americas;
            /*Random peso1 = new Random();
            double w11 = peso1.nextDouble();
            
            Random peso2 = new Random();
            double w12 = peso2.nextDouble();*/
            
            @Override
            public void run() {
                
                j = automovil.nextInt(2) + 0;
                i = automovil.nextInt(2) + 0;
                
                if(i == 1){
                    if(desviar_americas == -1){
                        autos_americas++;
                    }else{
                        autos_boyaca++;
                    }
                }
                    
                if(j == 1){
                    if(desviar_boyaca == -1){
                        autos_boyaca++;
                    }else{
                        autos_americas++;
                    }
                }
                
                if(desviar_americas == -1){
                    americas.offer(i);
                }else{
                    av_boyaca.offer(j);
                }
                
                if(desviar_boyaca == -1){
                    av_boyaca.offer(j);
                }else{
                    americas.offer(j);
                }

                while(av_boyaca.peek()!=null){
                    jTextArea1.setText(jTextArea1.getText()+"Av Boyaca: "+av_boyaca.poll()+" - ");
                }
                
                while(americas.peek()!=null){
                    jTextArea1.setText(jTextArea1.getText()+"Av Americas: "+americas.poll()+"\n");
                }
                    
                if(min == 60){
                    volumen_boyaca = autos_boyaca/60;
                    volumen_americas = autos_americas/60;
                    jTextArea1.setText("El volumen en la boyaca es: "+volumen_boyaca+", el volumen de las americas es: "+volumen_americas+"\n");
                    hebb hebb_boyaca = new hebb();
                    array_boyaca = hebb_boyaca.red(volumen_boyaca,w11);
                    desviar_boyaca = (int) array_boyaca[0];
                    w11 = array_boyaca[1];
                    
                    if(array_boyaca[2] == 1){
                        jTextArea1.setText(jTextArea1.getText()+"Desvio por las américas - ");
                    }else{
                        jTextArea1.setText(jTextArea1.getText()+"Debe seguir por la boyacá - ");
                    }
                    
                    hebb hebb_americas = new hebb();
                    array_americas = hebb_americas.red(volumen_americas,w12);
                    desviar_americas = (int) array_americas[0];
                    w12 = array_americas[1];
                    
                    if(array_americas[2] == 1){
                        jTextArea1.setText(jTextArea1.getText()+"Desvio por la boyacá\n");
                    }else{
                        jTextArea1.setText(jTextArea1.getText()+"Debe seguir por las américas \n");
                    }
                    
                    autos_boyaca = 0;
                    autos_americas = 0;
                    min = 0;
                }
                
                min ++;
            }
        };
        
        simulacion.schedule(task, 0, 1000);
    }//GEN-LAST:event_jButton1ActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Interfaz().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JScrollPane jScrollPane1;
    public javax.swing.JTextArea jTextArea1;
    // End of variables declaration//GEN-END:variables

}
