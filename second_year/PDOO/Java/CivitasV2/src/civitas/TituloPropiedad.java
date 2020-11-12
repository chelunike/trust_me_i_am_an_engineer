package civitas;

/**
 * @author chelunike
 */
public class TituloPropiedad {
    
    private final float factorInteresesHipoteca = (float) 1.1;
    
    private Jugador propietario;
    private float alquilerBase;
    private float factorRevalorizacion;
    private float hipotecaBase;
    private boolean hipotecado;
    private String nombre;
    private int numCasas;
    private int numHoteles;
    private float precioCompra;
    private float precioEdificar;
    
    
    public TituloPropiedad(String nombre, float alquilerBase, int factorRev, 
            float hipotecaBase, float precioCompra, float precioEdificar) {
        this.nombre = nombre;
        this.alquilerBase = alquilerBase;
        this.factorRevalorizacion = factorRev;
        this.hipotecaBase = hipotecaBase;
        this.precioCompra = precioCompra;
        this.precioEdificar = precioEdificar;
        this.hipotecado = false;
        this.propietario = null;
    }
    
    
    public float getPrecioAlquiler() {
        if ( !this.hipotecado && !this.propietarioEncarcelado() )
            return (float)(alquilerBase*(1+(numCasas*0.5)+(numHoteles*2.5)));
        return 0;
    }
    
    public float getImporteCancelarHipo() {
        return (float)(hipotecaBase*(1+(numCasas*0.5)+(numHoteles*2.5))) * 
                factorInteresesHipoteca;
    }
    
    public void tramitarAlquiler(Jugador jugador) {
        throw new UnsupportedOperationException("No implementado :C");
    }
    
    public boolean propietarioEncarcelado() {
        return (propietario != null && !propietario.isEncarcelado());
    }
    
    public int cantidadCasasHoteles() {
        return (numCasas + numHoteles);
    }
    
    public float getPrecioVenta() {
        return precioCompra+(numCasas+5*numHoteles)*precioEdificar*factorRevalorizacion;
    }
    
    public boolean derruirCasas(int n, Jugador jugador) {
        if (propietario == jugador && n <= numCasas) {
            numCasas -= n;
            return true;
        }
        return false;
    }
    
    public boolean vender(Jugador jugador) {
        if(propietario == jugador && !hipotecado) {
            propietario.recibe(this.getPrecioVenta());
            
            // Reset
            propietario = null;
            numCasas = 0;
            numHoteles = 0;
            return true;
        }
        return false;
    }
    
    
    // Por implementar
    //public boolean cancelarHipoteca (Jugador jugador) {}
    //public boolean hipotecar (Jugador jugador) {}
    //public boolean comprar(Jugador jugador) {}
    //public boolean construirCasa( Jugador jugador) {}
    //public boolean construirHotel( Jugador jugador) {}

    public Jugador getPropietario() {
        return propietario;
    }

    public boolean isHipotecado() {
        return hipotecado;
    }

    public String getNombre() {
        return nombre;
    }

    public int getNumCasas() {
        return numCasas;
    }

    public int getNumHoteles() {
        return numHoteles;
    }

    public float getPrecioCompra() {
        return precioCompra;
    }

    public float getPrecioEdificar() {
        return precioEdificar;
    }
    
    public String toString() {
        String result = "";
        result += this.nombre;
        result += this.alquilerBase;
        result += this.factorRevalorizacion;
        result += this.hipotecaBase;
        result += this.precioCompra;
        result += this.precioEdificar;
        return result;
    }

}
