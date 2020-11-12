package civitas;

import java.util.ArrayList;

/**
 *
 * @author chelunike
 */
class Sorpresa {
    
    private String texto;
    private int valor;
    private TipoSorpresa tipo;
    private MazoSorpresas mazo;
    private Tablero tablero;
    
    public Sorpresa(TipoSorpresa tipo, Tablero tablero) {
        init();
        this.tipo = tipo;
        this.tablero = tablero;
    }
    
    public Sorpresa(TipoSorpresa tipo, int valor, String texto) {
        init();
        this.tipo = tipo;
        this.valor = valor;
        this.texto = texto;
    }
    
    public Sorpresa(TipoSorpresa tipo, Tablero tablero, int valor, String texto) {
        init();
        this.tipo = tipo;
        this.tablero = tablero;
        this.valor = valor;
        this.texto = texto;
    }
    
    public Sorpresa(TipoSorpresa tipo, MazoSorpresas mazo) {
        init();
        this.tipo = tipo;
        this.mazo = mazo;
    }
    
    private void init() {
        valor = -1;
        tablero = null;
        mazo = null;
    }
    
    private void informe(int actual, ArrayList<Jugador> todos) {
        Diario.getInstance().ocurreEvento("Aplicando sorpresa a: "
                + todos.get(actual).getNombre());
    }
    
    public boolean jugadorCorrecto(int actual, ArrayList<Jugador> todos) {
        return (actual >= 0 && actual < todos.size());
    }
    
    public void aplicarAJugador(int actual, ArrayList<Jugador> todos) {
        if(jugadorCorrecto(actual, todos)) {
            informe(actual, todos);
            switch(tipo) {
                case IRCARCEL: aplicarAJugador_IRCARCEL(actual, todos);
                    break;
                case PAGARCOBRAR: aplicarAJugador_PAGARCOBRAR(actual, todos);
                    break;
                case IRCASILLA: aplicarAJugador_IRCASILLA(actual, todos);
                    break;
                case PORCASAHOTEL: aplicarAJugador_PORCASAHOTEL(actual, todos);
                    break;
                case PORJUGADOR: aplicarAJugador_PORJUGADOR(actual, todos);
                    break;
                case SALIRCARCEL: aplicarAJugador_SALIRCARCEL(actual, todos);
                    break;
            }
        }
    }
    
    private void aplicarAJugador_IRCARCEL(int actual, ArrayList<Jugador> todos) {
        Jugador jug = todos.get(actual);
        jug.encancerlar(tablero.getCarcel());
    }
    
    private void aplicarAJugador_IRCASILLA(int actual, ArrayList<Jugador> todos) {
        Jugador jug = todos.get(actual);
        int tirada = tablero.calcularTirada(actual, valor);
        int posicion = tablero.nuevaPosicion(actual, tirada);
        //tablero.moverACasilla(posicion);
        // se indica a la casilla que está en la posición del valor de la sorpresa que reciba al
        // jugador (método recibeJugador)
        throw new UnsupportedOperationException("Not supported yet :C"); 
    }
    
    private void aplicarAJugador_PAGARCOBRAR(int actual, ArrayList<Jugador> todos) {
        Jugador jug = todos.get(actual);
        jug.modificarSaldo(valor);
    }
    
    private void aplicarAJugador_PORCASAHOTEL(int actual, ArrayList<Jugador> todos) {
        Jugador jug = todos.get(actual);
        jug.modificarSaldo(valor*jug.getCasasPorHotel());
    }
    
    private void aplicarAJugador_PORJUGADOR(int actual, ArrayList<Jugador> todos) {
        Jugador jug = todos.get(actual);
        
        // Cobramos a los jugadores
        Sorpresa sorpresaCobro = new Sorpresa(TipoSorpresa.PAGARCOBRAR, valor*(-1), "Pago para: "+jug.getNombre());
        for (int i = 0; i < todos.size(); i++)
            if(i != actual)
                sorpresaCobro.aplicarAJugador(i, todos);
        
        // Pagamos al jugador
        // jug.modificaSaldo(valor*todos.size())
        Sorpresa sorpresaPago = new Sorpresa(TipoSorpresa.PAGARCOBRAR, valor*todos.size(), "Pago de todos");
        sorpresaPago.aplicarAJugador(actual, todos);
    }
    
    private void aplicarAJugador_SALIRCARCEL(int actual, ArrayList<Jugador> todos) {
        Jugador jug = todos.get(actual);
        boolean tieneSalvoConducto = false;
        for (int i = 0; i < todos.size(); i++) {
            tieneSalvoConducto |= todos.get(i).tieneSalvoconducto();
        }
        
        jug.obtenerSalvoconducto(this);
        this.salirDelMazo();
        
    }

    public void salirDelMazo() {
        if(tipo == TipoSorpresa.SALIRCARCEL) {
            mazo.inhabilitarCartaEspecial(this);
        }
    }
    
    public void usada() {
        if(tipo == TipoSorpresa.SALIRCARCEL) {
            mazo.habilitarCartaEspecial(this);
        }
    }
    
    public String toString() {
        return texto;
    }
    
}


