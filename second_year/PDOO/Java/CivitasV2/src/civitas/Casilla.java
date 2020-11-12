package civitas;

import java.util.ArrayList;

/**
 *
 * @author chelunike
 */
class Casilla {
    
    private String nombre;
    private int carcel;
    private float importe;
    private TipoCasilla tipo;
    private TituloPropiedad tituloPropiedad;
    private Sorpresa sorpresa;
    private MazoSorpresas mazo;
    
    public Casilla(String nombre) {
        init();
        this.tipo = TipoCasilla.DESCANSO;
        this.nombre = nombre;
    }
    
    public Casilla(TituloPropiedad tituloPropiedad) {
        init();
        this.tipo = TipoCasilla.CALLE;
        this.tituloPropiedad = tituloPropiedad;
        this.nombre = tituloPropiedad.getNombre();
    }
    
    public Casilla(float cantidad, String nombre) {
        init();
        this.tipo = TipoCasilla.IMPUESTO;
        this.importe = cantidad;
        this.nombre = nombre;
    }
    
    public Casilla(int numCasillaCarcel, String nombre) {
        init();
        this.tipo = TipoCasilla.JUEZ;
        this.carcel = numCasillaCarcel;
        this.nombre = nombre;
    }
    
    public Casilla(MazoSorpresas mazo, String nombre) {
        init();
        this.tipo = TipoCasilla.SORPRESA;
        this.mazo = mazo;
        this.nombre = nombre;
    }
    
    private void init() {
        this.nombre = "";
        this.carcel = -1;
        this.importe = 0;
        this.tituloPropiedad = null;
        this.sorpresa = null;
        this.mazo = null;
    }
    
    private void informe(int actual, ArrayList<Jugador> todos) {
        Diario.getInstance().ocurreEvento("El jugador: "
                + todos.get(actual).getNombre() 
                + " ha caido en la " + this.toString());
    }
    
    public boolean jugadorCorrecto(int actual, ArrayList<Jugador> todos) {
        return (actual >= 0 && actual < todos.size());
    }
    
    //public void recibeJugador(int actual, ArrayList<Jugador> todos) {}
    // No existe recibeJugador_descanso.
    //private void recibeJugador_calle(int actual, ArrayList<Jugador> todos) {}
    //private void recibeJugador_sorpresa(int actual, ArrayList<Jugador> todos) {}
    
    private void recibeJugador_impuesto(int actual, ArrayList<Jugador> todos) {
        if(this.jugadorCorrecto(actual, todos)) {
            informe(actual, todos);
            Jugador jug = todos.get(actual);
            jug.pagaImpuesto(importe);
        }
    }
    
    private void recibeJugador_juez(int actual, ArrayList<Jugador> todos) {
        if(this.jugadorCorrecto(actual, todos)) {
            informe(actual, todos);
            Jugador jug = todos.get(actual);
            jug.encancerlar(carcel);
        }
    }
    
    public TituloPropiedad getTituloPropiedad() {
        return tituloPropiedad;
    }

    public String getNombre() {
        return nombre;
    }
    
    public String toString() {
        return "Casilla: " + nombre + " Tipo: " + tipo;
    }
    
}
