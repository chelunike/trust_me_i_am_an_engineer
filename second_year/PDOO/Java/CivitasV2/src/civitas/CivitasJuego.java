package civitas;

import java.util.ArrayList;

/**
 * @author chelunike
 */
public class CivitasJuego {
    
    private Tablero tablero;
    private MazoSorpresas mazo;
    private EstadosJuego estado;
    private GestorEstados gestorEstados;
    
    private ArrayList<Jugador> jugadores;
    private int indiceJugadorActual;
    
    // Nota: Implementar mas tarde con las reglas del juego
    
    public CivitasJuego(String... jugadores) {
        // Creamos los jugadores
        this.jugadores = new ArrayList<>();
        for(String jugador : jugadores)
            this.jugadores.add(new Jugador(jugador));
        
        // Inicializamos GestorEstados y estado
        this.gestorEstados = new GestorEstados();
        this.estado = this.gestorEstados.estadoInicial();
        
        // Elegimos quien empieza
        this.indiceJugadorActual = Dado.getInstance().quienEmpieza(this.jugadores.size());
        
        // Mazo de sorpresas
        this.mazo = new MazoSorpresas();
        
        // Inicializamos tablero y mazo
        inicializaTablero(mazo);
        inicializaMazoSorpresas(tablero);
    }
    
    
    // Por implementar
    // public void avanzaJugador() {}
    // public OperacionesJuego siguientePaso () {}
    // public boolean comprar() {}
    
    public void inicializaTablero(MazoSorpresas mazo) {
        // Creando tablero
        this.tablero = new Tablero(5);
        
        // Datos comunes
        float alquilerBase = 100;
        int factorRev = 3;
        float precioEdificar = 200;
        
        // Añadiendo Casillas
        tablero.añadeCasilla(new Casilla("Salida"));
        //TituloPropiedad calle1 = new TituloPropiedad("Calle ", alquilerBase, factorRev, hipotecaBase, precioCompra, precioEdificar)
        TituloPropiedad calle1 = new TituloPropiedad("Calle 2", alquilerBase, factorRev, 50, 60, precioEdificar);
        TituloPropiedad calle2 = new TituloPropiedad("Calle 3", alquilerBase, factorRev, 50, 80, precioEdificar);
        tablero.añadeCasilla(new Casilla(calle1));
        tablero.añadeCasilla(new Casilla(calle2));
        tablero.añadeCasilla(new Casilla(mazo, "Sorpresa"));
        TituloPropiedad calle3 = new TituloPropiedad("Calle 5", alquilerBase, factorRev, 100, 120, precioEdificar);
        tablero.añadeCasilla(new Casilla(calle3));
        tablero.añadeCasilla(new Casilla(5, "Carcel"));
        TituloPropiedad calle4 = new TituloPropiedad("Calle 7", alquilerBase, factorRev, 100, 1240, precioEdificar);
        tablero.añadeCasilla(new Casilla(calle4));
        tablero.añadeCasilla(new Casilla(10.5f, "Imputesto"));
        TituloPropiedad calle5 = new TituloPropiedad("Calle 9", alquilerBase, factorRev, 150, 160, precioEdificar);
        tablero.añadeCasilla(new Casilla(calle5));
        TituloPropiedad calle6 = new TituloPropiedad("Calle 10", alquilerBase, factorRev, 150, 200, precioEdificar);
        tablero.añadeCasilla(new Casilla(calle6));
        tablero.añadeCasilla(new Casilla("Parking"));
        TituloPropiedad calle7 = new TituloPropiedad("Calle 12", alquilerBase, factorRev, 200, 220, precioEdificar);
        tablero.añadeCasilla(new Casilla(calle7));
        tablero.añadeCasilla(new Casilla(mazo, "Sorpresa"));
        TituloPropiedad calle8 = new TituloPropiedad("Calle ", alquilerBase, factorRev, 200, 260, precioEdificar);
        tablero.añadeCasilla(new Casilla(calle8));
        TituloPropiedad calle9 = new TituloPropiedad("Calle ", alquilerBase, factorRev, 250, 280, precioEdificar);
        tablero.añadeCasilla(new Casilla(calle9));
        tablero.añadeCasilla(new Casilla(15, "Carcel"));
        TituloPropiedad calle10 = new TituloPropiedad("Calle ", alquilerBase, factorRev, 250, 300, precioEdificar);
        tablero.añadeCasilla(new Casilla(calle10));
        tablero.añadeCasilla(new Casilla(mazo, "Sorpresa"));
        TituloPropiedad calle11 = new TituloPropiedad("Calle ", alquilerBase, factorRev, 300, 350, precioEdificar);
        tablero.añadeCasilla(new Casilla(calle11));
        TituloPropiedad calle12 = new TituloPropiedad("Calle ", alquilerBase, factorRev, 300, 400, precioEdificar);
        tablero.añadeCasilla(new Casilla(calle12));

    }
    
    public void inicializaMazoSorpresas(Tablero tablero) {
        // Creando cartas sorpresa
        
    }
    
    public void contabilizarPasosPorSalida(Jugador jugadorActual) {
    
    }
    
    public void pasarTurno() {
    
    }
    
    public void sisguientePasoConmpletado(OperacionesJuego operacion) {
    
    }
    
    public boolean construirCasa(int ip) {
    
    }
    
    public boolean construirHotel(int ip) {
    
    
    }
    
    public boolean vender(int ip) {
    
    }
    
    public boolean hipotecar(int ip) {
    
    }
    
    public boolean cancelarHipoteca(int ip) {
    
    }
    
    public boolean salirCarcelPagando() {
    
    }
    
    public boolean salirCarcelTirando() {
    
    }
    
    public boolean finalDelJuego() {
    
    }
    
    public ArrayList<Jugador> ranking() {
        return jugadores.sort();
    }
    
}

