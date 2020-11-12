package civitas;

import java.util.Random;

/**
 *
 * @author chelunike
 */
public class Dado {
    
    // Atributos de instancia
    private Random random;
    private int ultimoResultado;
    private boolean debug;
    
    // Atributos de clase
    private static final Dado instance = new Dado();
    private static int SalidaCarcel = 5;
    
    private static final int MAX_DADO = 6;
    private static final int MIN_SALIR_CARCEL = 5;
    
    static public Dado getInstance() {
        return instance;
    }
    
    private Dado() {
        this.random = new Random();
        this.ultimoResultado = 0;
        this.debug = false;
    }
    
    public int tirar() {
        if (debug)
            return 1;
        return random.nextInt(MAX_DADO+1);
    }
    
    public boolean salgoDeLaCarcel() {
        return (tirar() >= MIN_SALIR_CARCEL);
    }
    
    public int quienEmpieza(int n) {
        return random.nextInt(n);
    }
    
    public void setDebug(boolean d) {
        this.debug = d;
    }
    
    public int getUltimoResultado() {
        return this.ultimoResultado;
    }
    
}
