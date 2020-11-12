package civitas;

import java.util.ArrayList;

/**
 *
 * @author chelunike
 */
public class Tablero {
    
    // Atributos
    private int numCasillaCarcel;
    private ArrayList<Casilla> casillas;
    private int porSalida;
    private boolean tieneJuez;
    
    
    // Contructor
    public Tablero(int numCasillaCarcel) {
        this.numCasillaCarcel = numCasillaCarcel;
        this.casillas = new ArrayList<Casilla>();
        this.porSalida = 0;
        this.tieneJuez = false;
    }
    
    // Metodos privados 
    private boolean correcto() {
        return (casillas.size() > numCasillaCarcel) && tieneJuez;
    }
    
    private boolean correcto(int numCasilla) {
        return (correcto() && numCasilla < casillas.size());
    }
    
    
    // Metodos publicos
    public int getCarcel() {
        return this.numCasillaCarcel;
    }
    
    public int getPorSalida() {
        return this.porSalida;
    }
    
    public void añadeCasilla(Casilla casilla) {
        if (casillas.size() == (numCasillaCarcel - 1))
            casillas.add(new Casilla("Carcel"));
        casillas.add(casilla);
        
        if (casillas.size() == numCasillaCarcel)
            casillas.add(new Casilla("Carcel"));
    }
    
    public void añadeJuez() {
        if (!tieneJuez)
            casillas.add(new Casilla("Carcel"));
        tieneJuez = true;
    }
    
    public Casilla getCasilla(int numCasilla) {
        if(correcto(numCasilla))
            return this.casillas.get(numCasilla);
        return null;
    }
    
    public int nuevaPosicion(int actual, int tirada) {
        if (!correcto(actual))
            return -1;
        
        int pos = actual + tirada;
        if (pos >= casillas.size()) {
           pos = casillas.size();
           porSalida++;
        }
        return pos;
    }
    
    public int calcularTirada(int origen, int destino) {
        throw new UnsupportedOperationException("No implementado :C");
    }
    
    
}

