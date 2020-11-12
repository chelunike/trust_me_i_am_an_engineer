package civitas;

import java.util.ArrayList;

/**
 *
 * @author chelunike
 */
public class Jugador implements Comparable<Jugador> {
    
    public static final int CasasMax = 4;
    public static final int CasasPorHotel = 4;
    public static final int HotelesMax = 4;
    public static final float PasoPorsalida = 1000;
    public static final float PrecioLibertad = 200;
    public static final float SaldoInicial = 7500;
    
    private String nombre;
    private int numCasillaActual;
    private boolean puedeComprar;
    protected boolean encarcelado;
    private float saldo;
    private ArrayList<TituloPropiedad> propiedades;
    private Sorpresa salvoconducto;
    
    public Jugador(String nombre) {
        this.nombre = nombre;
        this.numCasillaActual = 0;
        this.puedeComprar = true;
        this.encarcelado = false;
        this.saldo = SaldoInicial;
        this.propiedades = new ArrayList<>();
        this.salvoconducto = null;
    }
    
    protected Jugador(Jugador otro) {
        this.nombre = otro.nombre;
        this.numCasillaActual = 0;
        this.puedeComprar = true;
        this.encarcelado = false;
        this.saldo = SaldoInicial;
        this.propiedades = new ArrayList<>();
        this.salvoconducto = null;
    }
    
    // Implementar mas tarde
    // public cancelarHipoteca (int ip) {}
    // public comprar (TituloPropiedad titulo)• construirHotel (int ip) {}
    // public construirCasa (int ip) {}
    // public hipotecar (int ip) {}
    
    public boolean debeSerEncarcelado() {
        if(!encarcelado) {
            if (tieneSalvoconducto()) {
                perderSalvoconducto();
                Diario.getInstance().ocurreEvento("Jugador : "+nombre+" se libra de la carcel.");
                return false;
            } else
                return true;
        }    
        return false;
    }
    
    public boolean encancerlar(int numCasillaCarcel) {
        if(debeSerEncarcelado()) {
            moverACasilla(numCasillaCarcel);
            encarcelado = true;
            return true;
        }
        return false;
    }
    
    public boolean obtenerSalvoconducto(Sorpresa s) {
        if(!encarcelado) {
            salvoconducto = s;
            return true;
        }
        return false;    
    }
    
    public void perderSalvoconducto() {
        if(tieneSalvoconducto())
            salvoconducto.usada();
        salvoconducto = null;
    }
    
    public boolean tieneSalvoconducto() {
        return (salvoconducto != null);
    }
    
    public boolean puedoComprarCasilla() {
        puedeComprar = !encarcelado;
        return puedeComprar;
    }
    
    public boolean paga(float cantidad) {
        return modificarSaldo(cantidad * (-1));
    }
    
    public boolean pagaImpuesto(float cantidad) {
        if(encarcelado)
            return paga(cantidad);
        return false;
    }
    
    public boolean pagaAlquiler(float cantidad) { // por ahora
        if(encarcelado)
            return paga(cantidad);
        return false;
    }
    
    public boolean recibe(float cantidad) {
        if(encarcelado)
            return false;
        return modificarSaldo(cantidad);
    }
    
    public boolean modificarSaldo(float cantidad) {
        saldo += cantidad;
        Diario.getInstance().ocurreEvento("Jugador " + nombre
                + " modifica saldo: " + cantidad 
                + " Total: " + saldo);
        return true;
    }
    
    boolean moverACasilla(int numCasilla) {
        if (!encarcelado) {
            numCasillaActual = numCasilla;
            puedeComprar = false;
            Diario.getInstance().ocurreEvento("Jugador" 
                    + nombre + "se mueve a " +numCasillaActual);
            return true;
        }
        return false;
    }
    
    public boolean puedoGastar(float precio) {
        return (!encarcelado && (saldo >= precio));
    }
    
    public boolean vender(int ip) {
        if(!encarcelado && existePropiedad(ip)) {
            TituloPropiedad prop = propiedades.get(ip);
            if (prop.vender(this)) {
                propiedades.remove(prop);
                Diario.getInstance().ocurreEvento("Jugador "
                        + nombre + " vende: " + prop.getNombre());
                return false;
            }
        }
        return false;
    }
    
    public boolean tieneAlgoQueGestionar() {
        return (propiedades.size() > 0);
    }
    
    public boolean puedeSalirCarcelPagando() {
        return (saldo >= PrecioLibertad);
    }
    
    public boolean salirCarcelPagando() {
        if(encarcelado && puedeSalirCarcelPagando() && paga(PrecioLibertad)) {
            encarcelado = false;
            Diario.getInstance().ocurreEvento(" Jugador " + nombre 
                    + "sale de la carcel pagando");
            return true;
        }
        return false;
    }
    
    public boolean salirCarcelTirando() {
        if(Dado.getInstance().salgoDeLaCarcel()) {
            encarcelado = false;
            Diario.getInstance().ocurreEvento(" Jugador " + nombre 
                    + "sale de la carcel tirando");
            return true;
        }
        return false;
    }
    
    public boolean pasarPorsalida() {
        modificarSaldo(PasoPorsalida);
        Diario.getInstance().ocurreEvento("Jugador "+nombre+" pasa por salida");
        return true;
    }
    
    @Override
    public int compareTo(Jugador j) {
        return (int)(this.saldo - j.getSaldo());
    }
    
    // Getters

    public int getCasasMax() {
        return CasasMax;
    }

    public int getCasasPorHotel() {
        return CasasPorHotel;
    }

    public int getHotelesMax() {
        return HotelesMax;
    }

    public float getPremioPasoPorsalida() {
        return PasoPorsalida;
    }

    public float getPrecioLibertad() {
        return PrecioLibertad;
    }

    public String getNombre() {
        return nombre;
    }

    public int getNumCasillaActual() {
        return numCasillaActual;
    }

    public float getSaldo() {
        return saldo;
    }

    public ArrayList<TituloPropiedad> getPropiedades() {
        return propiedades;
    }

    public boolean isPuedeComprar() {
        return puedeComprar;
    }
    
    boolean isEncarcelado() {
        return encarcelado;
    }

    private boolean existePropiedad(int ip) {
        return (ip >= 0 && ip <= propiedades.size());
    }
    
    
}
