package civitas;


import java.util.ArrayList;
import java.util.Collections;
/**
 *
 * @author chelunike
 */
public class MazoSorpresas {
    
    // Atributos
    private ArrayList<Sorpresa> sorpresas;
    private boolean barajada;
    private int usadas;
    private boolean debug;
    private ArrayList<Sorpresa> cartasEspeciales;
    private Sorpresa ultimaSorpresa;
    
    // Constructor
    public MazoSorpresas() {
        this.debug = false;
        init();
    }
    
    public MazoSorpresas(boolean debug) {
        this.debug = debug;

        init();
    }
    
    // Metodo privado
    private void init() {
        this.sorpresas = new ArrayList<Sorpresa>();
        this.barajada = false;
        this.usadas = 0;
        this.cartasEspeciales = new ArrayList<Sorpresa>();
    }
    
    // Metodos publicos
    public void alMazo(Sorpresa s) {
        if (!barajada)
            sorpresas.add(s);
    }
    
    public Sorpresa siguiente() {
        if( (!barajada || usadas == sorpresas.size()) && !debug) {
            Collections.shuffle(sorpresas);
            barajada = true;
            usadas = 0;
        }
        
        Sorpresa sorpresa = sorpresas.get(0);
        sorpresas.remove(0);
        sorpresas.add(sorpresa);
        usadas++;
        
        return sorpresa;
    }
    
    /**
     * la sorpresa que recibe como argumento es una 
     * carta especial. Si está en el mazo, se quita del mismo para que no se use,
     * y se añade a     cartasEspeciales. Si la operación se realiza se deja
     * constancia en el diario.
     * 
     * @param sorpresa 
     */
    public void inhabilitarCartaEspecial(Sorpresa sorpresa) {
        throw new UnsupportedOperationException("No implementado :C");
    }
    
    public void habilitarCartaEspecial(Sorpresa sorpresa) {
        throw new UnsupportedOperationException("No implementado :C");
    }
    
}
