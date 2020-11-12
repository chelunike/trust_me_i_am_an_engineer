package civitas;

import java.util.Arrays;

/**
 *
 * @author chelunike
 */
public class TestP2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Dado dado = Dado.getInstance();
        
        // 1. Tirar 100 veces el dado
        int[] jugadores = {0, 0, 0, 0};
        for(int i=0; i<100; i++)
            jugadores[dado.quienEmpieza(4)]++;
        
        System.out.println("Numero de veces que empiezan: " + Arrays.toString(jugadores));
        
        //2. Probar el modo debug del dado
        int tiradasNormales = 0, tiradasDebug = 0;
        
        dado.setDebug(true);
        for(int i=0; i<10; i++)
            tiradasDebug += dado.tirar();
        
        dado.setDebug(false);
        for(int i=0; i<10; i++)
            tiradasNormales += dado.tirar();
        
        System.out.println("10 Tiradas Normales: " + tiradasNormales);
        System.out.println("10 Tiradas Debug: " + tiradasDebug);
        
        //3. Probando metodos
        System.out.println("Ultimo resultado: " + dado.getUltimoResultado());
        System.out.println("Salir de la carcel: " + dado.salgoDeLaCarcel());
        
        //4. Probar los tipos enumerados
        EstadosJuego estado = EstadosJuego.DESPUES_AVANZAR;
        System.out.println("Estado de juego: " + estado);
        
        //5. Probando MazoSopresas
        System.out.println("Creando mazo y rellenando.");
        MazoSorpresas mazo = new MazoSorpresas();
        
//        Sorpresa s1 = new Sorpresa("Sorpresa 1");
//        Sorpresa s2 = new Sorpresa("Sorpresa 2");
//        
//        mazo.alMazo(s1);
//        mazo.alMazo(s2);
//        
//        Sorpresa siguiente = mazo.siguiente();  
//        System.out.println("Sorpresa siguiente: " + siguiente);
//        
//        mazo.inhabilitarCartaEspecial(s2);
//        mazo.habilitarCartaEspecial(s2);
//        
        //6. Probar diario
        Diario diario = Diario.getInstance();
        
        // Eventos
        System.out.println("Eventos pendientes: " + diario.eventosPendientes());
        System.out.println("Añado evento");
        diario.ocurreEvento("No le he enchufado");
        System.out.println("Eventos pendientes: " + diario.eventosPendientes());
        System.out.println("Eventos: " + diario.leerEvento());
        
        //7. Probar tablero
        Tablero tablero = new Tablero(1);
        
    }
    
}
