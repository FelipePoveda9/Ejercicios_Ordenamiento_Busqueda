#include <iostream>
#include <ctime>
#include <string>

using namespace std;

// Clase Tienda PRODUCTO , STOCK, PRECIO

//clase Tienda
class Tienda {
    private:
        int producto;
        int stock;
        int precio;
    public:
        Tienda() {
            producto = -1; 
            stock = -1;
            precio = -1;
        }
        Tienda(int producto, int stock, int precio) {
            this -> producto = producto;
            this -> stock = stock;
            this -> precio = precio;
        }
        
        //Getters y Setters
        int getProducto() const { 
            return producto; 
        }

        int getStock() const { 
            return stock; 
        }
    
        int getPrecio() const { 
            return precio; 
        }

    
        Tienda& operator=(const Tienda& f) {
            producto = f.producto;
            stock = f.stock;
            precio = f.precio;
            return *this;
        }
    
        string to_string() const {
            return "Producto: " + std::to_string(producto) + ", Stock: " + std::to_string(stock) + ", Precio: $" + std::to_string(precio);
        }
    
        friend std::ostream& operator<<(std::ostream& os, const Tienda& s) {
            return os << s.to_string();
        }

        bool operator>(const Tienda& f) const {
            return precio > f.precio;
        }

        bool operator<(const Tienda& f) const {
            return precio < f.precio;
        }
    
    };


// Clase nodo con plantilla Juan Felipe Poveda 
template <typename T>
class Nodo{
    private:
        T valor;
        Nodo<T>* siguiente;
    public:
        // constructor 
        Nodo(T _valor) : valor(_valor), siguiente(nullptr){}

        // Metodo setter para ajustar siguiente
        void setSiguiente(Nodo<T>* _siguiente){
            this -> siguiente = _siguiente;
        }

        // Metodo setter para ajustar valor
        void setValor(T _valor){
            this -> valor = _valor;
        }

        // Metodo getter para valor
        T getValor(){
            return valor;
        }

        // Metodo getter paar siguiente
        Nodo<T>* getSiguiente(){
            return siguiente;
        }
};

//poner aquí su código de listas con los comentarios realizados en las clases
//Juan Felipe Poveda 
template <typename T>
class ListaEnlazada{
private: 
    Nodo<T>* cabeza; // Apuntador al primer nodo de la lista
    int size;
public:
    // Constructor inicializa la lista como vacía
    ListaEnlazada(): cabeza(nullptr), size(0) {};
    
    // Destructor que libera la memoria de la lista
    ~ListaEnlazada(){
        Nodo<T>* actual = cabeza;
        Nodo<T>* siguiente = nullptr;
        while(actual != nullptr){
            siguiente = actual -> getSiguiente(); // Guardamos la dirección del siguiente nodo
            delete actual; // Liberamos el nodo actual
            actual = siguiente; // Avanzamos al siguiente nodo
        }
    }
    
    // Método para insertar nodos al final de la lista Juan Felipe Poveda 
    void insertar(T _valor){
        Nodo<T>* nuevoNodo = new Nodo<T>(_valor);
        if(cabeza == nullptr){ // Si la lista está vacía, el nuevo nodo es la cabeza
            cabeza = nuevoNodo;
        }else{
            Nodo<T>* actual = cabeza;
            while(actual -> getSiguiente()){ // Recorremos hasta el último nodo
                actual = actual -> getSiguiente();
            }
            actual -> setSiguiente(nuevoNodo); // Se enlaza el nuevo nodo al final
        }
        size ++;
    }

    // Método para insertar un nodo en una posición específica Juan Felipe Poveda 
    void insertarEnPosicion(int posicion, const T& _valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(_valor);

        if (posicion == 0) {
            nuevoNodo->setSiguiente(cabeza);
            cabeza = nuevoNodo;
            return;
        }

        Nodo<T>* actual = cabeza;
        int contador = 0;
        while (actual != nullptr && contador < (posicion - 1)) {
            actual = actual->getSiguiente();
            contador++;
        }

        if (actual == nullptr) {
            std::cout << "Posición inválida" << std::endl;
            delete nuevoNodo;
            return;
        }

        nuevoNodo->setSiguiente(actual->getSiguiente());
        actual->setSiguiente(nuevoNodo);
    }
    
    Nodo<T>* buscarPorValor(const T& _valor) const {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            if (actual->getValor() == _valor) {
                return actual;
            }
            actual = actual->getSiguiente();
        }
        return nullptr;
    }

    int get_size() const { return size; }

    // Método para mostrar la lista Juan Felipe Poveda 
    void mostrar() const {
        Nodo<T>* actual = cabeza;
        cout << "Lista de valores: " << endl;
        while (actual != nullptr) {
            cout << actual->getValor() << endl;
            actual = actual->getSiguiente();
        }
        cout << "nullptr" << endl; // Indicamos el final de lista
    }

    Nodo<T>* get(int i) const {
        if (i >= 0 && i < size) {
            int j = 0;
            Nodo<T>* actual = cabeza;
            while (j < i) {
                actual = actual->getSiguiente();
                j++;
            }
            return actual;
        }
        return nullptr;
    }
    

    void swap(int px, int py) {
        if (px == py) return; // Si son la misma posición, no hay nada que intercambiar
    
        Nodo<T>* prevX = nullptr, *nodoX = cabeza;
        Nodo<T>* prevY = nullptr, *nodoY = cabeza;
    
        // Buscar nodoX y su nodo anterior
        for (int i = 0; nodoX != nullptr && i < px; i++) {
            prevX = nodoX;
            nodoX = nodoX->getSiguiente();
        }
    
        // Buscar nodoY y su nodo anterior
        for (int i = 0; nodoY != nullptr && i < py; i++) {
            prevY = nodoY;
            nodoY = nodoY->getSiguiente();
        }
    
        // Si no encontramos uno de los nodos, no intercambiar
        if (nodoX == nullptr || nodoY == nullptr) return;
    
        // Si nodoX no es la cabeza, conectamos su anterior a nodoY
        if (prevX != nullptr)
            prevX->setSiguiente(nodoY);
        else // Si nodoX era la cabeza, ahora nodoY será la cabeza
            cabeza = nodoY;
    
        // Si nodoY no es la cabeza, conectamos su anterior a nodoX
        if (prevY != nullptr)
            prevY->setSiguiente(nodoX);
        else // Si nodoY era la cabeza, ahora nodoX será la cabeza
            cabeza = nodoX;
    
        // Intercambiamos los punteros siguientes de nodoX y nodoY
        Nodo<T>* temp = nodoX->getSiguiente();
        nodoX->setSiguiente(nodoY->getSiguiente());
        nodoY->setSiguiente(temp);
    }

    void bubbleSort(){
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                Nodo<T>* nodoA = get(j);
                Nodo<T>* nodoB = get(j + 1);
                if (nodoA->getValor().getPuntuacion() > nodoB->getValor().getPuntuacion()) {
                    swap(j, j + 1);
                }
            }
        }
    }

    void selectionSort() {
        for (int i = 0; i < size - 1; i++) {
            Nodo<T>* minNode = get(i);
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                Nodo<T>* actual = get(j);
                if (actual->getValor().getPuntuacion() < minNode->getValor().getPuntuacion()) {
                    minNode = actual;
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                swap(i, minIndex);
            }
        }
    }

    void shellSort() {
        int sizered = size / 2;

        while (sizered > 0) {
            for (int i = sizered; i < size; i++) {
                int j = i - sizered;
                while (j >= 0) {
                    int k = j + sizered;
                    if (get(j)->getValor().getPuntuacion() <= get(k)->getValor().getPuntuacion()) {
                        j = -1;
                    } else {
                        swap(j, k);
                    }
                    j = j - sizered;
                }
            }
            sizered = sizered / 2;
        }
    }

    void insertionSort() {
        for (int i = 1; i < size; i++) {
            Nodo<T>* actual = get(i);
            int j = i - 1;
            while (j >= 0 && get(j)->getValor().getPuntuacion() > actual->getValor().getPuntuacion()) {
                swap(j, j + 1);
                j--;
            }
            get(j + 1)->setValor(actual->getValor());
        }
    }

    int partition(int low, int high, bool ascendente) {
        Nodo<T>* pivot = get(high); // Elegimos el último elemento como pivote
        int cambio = low - 1; // Índice del elemento más pequeño

        for (int comparar = low; comparar < high; comparar++) {
            if (get(comparar)->getValor().getPuntuacion() < pivot->getValor().getPuntuacion()) {
                cambio++;
                swap(comparar, cambio); // Intercambiamos elementos
            }
        }
        swap(cambio + 1, high); // Colocamos el pivote en su posición correcta
        return cambio + 1;
    }

    void quickSort(int low, int high, bool ascendente) {
        if (low < high) {
            int pivotIndex = partition(low, high, ascendente);
            quickSort(low, pivotIndex - 1, ascendente);
            quickSort(pivotIndex + 1, high, ascendente);
        }
    }

    // Método para dividir la lista en dos mitades Juan Felipe Poveda
    // y mezclar las dos mitades ordenadas
    Nodo<T>* split(Nodo<T>* cabeza) {
        if (cabeza == nullptr || cabeza->getSiguiente() == nullptr) {
            return nullptr; // Si la lista es vacía o de un solo nodo, no se divide
        }

        Nodo<T>* slow = cabeza; // avanza de a 1 nodo
        Nodo<T>* fast = cabeza->getSiguiente(); // avanza de a 2 nodos

        while (fast != nullptr && fast->getSiguiente() != nullptr) {
            slow = slow->getSiguiente(); // avanza de a 1 paso
            fast = fast->getSiguiente()->getSiguiente(); // avanza de a 2 pasos
        }

        Nodo<T>* medio  = slow->getSiguiente(); // inicio de la segunda mitad
        slow->setSiguiente(nullptr); // Parte la lista en dos partes
        return medio ;
    }

    Nodo<T>* merge(Nodo<T>* left, Nodo<T>* right) {
        if (!left) return right;
        if (!right) return left;
    
        if (left->getValor().getPuntuacion() > right->getValor().getPuntuacion()) {
            std::swap(left, right); // Asegurar que left siempre tenga el menor valor
        }
    
        Nodo<T>* cabeza = left; // El inicio siempre es el menor
    
        while (left->getSiguiente() && right) { // Mientras haya nodos en ambas listas
            if (left->getSiguiente()->getValor().getPuntuacion() > right->getValor().getPuntuacion()) {
                Nodo<T>* temp = right; // Guardamos el nodo de la lista derecha
                right = right->getSiguiente(); // Avanzamos en la lista derecha
                temp->setSiguiente(left->getSiguiente()); // Enlazamos el nodo de la lista derecha al siguiente de left
                left->setSiguiente(temp); 
            }
            left = left->getSiguiente(); // Avanzamos en izquierda
        }
    
        if (!left->getSiguiente()) {
            left->setSiguiente(right);
        }
    
        return cabeza; // Retornar el inicio de la lista fusionada
    }

    Nodo<T>* mergeSort(Nodo<T>* cabeza) {
        if (cabeza == nullptr || cabeza->getSiguiente() == nullptr) {
            return cabeza;
        }

        Nodo<T>* medio  = split(cabeza); // Divide la lista en dos partes
        Nodo<T>* left = mergeSort(cabeza); // Me ordena la parte izquierda
        Nodo<T>* right = mergeSort(medio ); // Me ordena la parte derecha
        return merge(left, right); // Mezcla las dos partes ordenadas
    }

    void mergeSort() {
        cabeza = mergeSort(cabeza);
    }

    void busquedaBinariaRango(int precioMinimo, int precioMaximo) {
        if (precioMinimo > precioMaximo || size == 0) {
            cout << "Rango invalido." << endl;
            return;
        }
    
        int inicio = 0, fin = size - 1;
        ListaEnlazada<T> encontrados;
    
        while (inicio <= fin) {
            int medio  = inicio + (fin - inicio) / 2;
            Nodo<T>* nodoMedio = get(medio);
            int precioMedio  = nodoMedio->getValor().getPuntuacion();
    
            if (precioMedio  >= precioMinimo && precioMedio  <= precioMaximo) {
                int left = medio ;
                while (left >= 0 && get(left)->getValor().getPuntuacion() >= precioMinimo) {
                    encontrados.insertar(get(left)->getValor());
                    left--;
                }
    
                int right = medio  + 1;
                while (right < size && get(right)->getValor().getPuntuacion() <= precioMaximo) {
                    encontrados.insertar(get(right)->getValor());
                    right++;
                }
                break;
            }
    
            if (precioMedio  < precioMinimo) {
                inicio = medio  + 1;
            } else {
                fin = medio  - 1;
            }
        }
        cout << "_________________________________________" << endl;
        cout << endl;
        cout << "encontrados en el rango de [" << precioMinimo << ", " << precioMaximo << "]:" << endl;
        encontrados.mergeSort();
        cout << "_________________________________________" << endl;
        encontrados.mostrar();
    }
};


// Clase ProductoPrecio
class ProductoPrecio {
private:
    ListaEnlazada<Tienda> precio;
    int* arreglo;
    int np1;
    int ns;
    int np;
    int nump;

public:
    ProductoPrecio(int producto = 20, int stock = 20, int precio = 20, int Num_produc = 200): np1(producto), ns(stock), np(precio), nump(Num_produc) {
    }

    ~ProductoPrecio() {
    }
    
    //crear el método init_lista() Juan Felipe Poveda 
    void init_lista() {
       Tienda* z;
       int producto , s, p;
       for (int i = 0; i < nump; i++){
        producto = rand() % np1;
        s = rand() % ns;
        p = rand() % np;
        z = new Tienda(producto, s, p);
        precio.insertar(*z);
       }
       cout << "_________________________________________" << endl;
       cout << "Se han generado " << precio.get_size() << " productos en el inventario." << endl;
       precio.mostrar();
       cout << "_________________________________________" << endl;
    }

    void ordenar() {
        precio.mergeSort();
    }

    void busquedaBinaria(int precioMinimo, int precioMaximo) {
        precio.busquedaBinariaRango(precioMinimo, precioMaximo);
    }

    // Mostrar la lista de productos
    void print() {
        precio.mostrar();
    }
};

int main() {
    ListaEnlazada<string> ListaEnlazada;

    srand(time(0));  // Inicialización del generador de números aleatorios Juan Felipe Poveda 
    int producto = 20;
    int s = 20;
    int p = 200;
    int s1 = 20;
    int opc = 1;
    int precioMinimo, precioMaximo;

    ProductoPrecio produc = ProductoPrecio(producto, s, p, s1);
    produc.init_lista();
    cout<<endl;

    produc.ordenar();
    cout << "Lista ordenada por precio más bajo a más alto: " << endl;
    produc.print();
    cout << endl;

    while (opc == 1) {
        cout << "\tBusqueda de productos" << endl;
        cout << "_________________________________________" << endl;
        cout << endl;

        cout << "\tRango minimo de precio: " << endl;
        cin >> precioMinimo;
        cout << "_________________________________________" << endl;
        cout << endl;

        cout << "\tRango maximo de precio: " << endl;
        cin >> precioMaximo;
        produc.busquedaBinaria(precioMinimo, precioMaximo);
        cout << endl;
        cout << "_________________________________________" << endl;
        cout << endl;

        cout << "¿Realizar otra búsqueda? (1/Sí , 0/No): ";
        cin >> opc;
        cout << endl;
    }

    return 0;
}
