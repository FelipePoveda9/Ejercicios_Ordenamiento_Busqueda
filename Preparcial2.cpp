//encontrados.
//puntuacion.
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

// Clase Cinema Pelicula , Puntuacion

//clase Cinema
class Calificacion {
private:
    int grupo;
    int puntuacion;
public:
    Calificacion() {
        grupo = -1; 
        puntuacion = -1; 
    }
    Calificacion(int grupo, int puntuacion) {
        this -> grupo = grupo;
        this -> puntuacion = puntuacion;
    }

    int getPuntuacion() const { 
        return puntuacion; 
    }

     string to_string() const {
        return "" + std::to_string(grupo) + ", "  + std::to_string(puntuacion);
    }

    friend std::ostream& operator<<(std::ostream& os, const Calificacion& c) {
        return os << c.to_string();
    }

    bool operator<(const Calificacion& p){
        return this->puntuacion < p.getPuntuacion();
    }

    bool operator>(const Calificacion& p){
        return this->puntuacion > p.getPuntuacion();
    }

    bool operator<=(const Calificacion& p){
        return this->puntuacion <= p.getPuntuacion();
    }

    bool operator>=(const Calificacion& p){
        return this->puntuacion >= p.getPuntuacion();
    }

    bool operator==(const Calificacion& p){
        return this->puntuacion == p.getPuntuacion();
    }

    bool operator!=(const Calificacion& p){
        return this->puntuacion != p.getPuntuacion();
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
    // Método para obtener el tamaño de la lista
    // Método para mostrar la lista Juan Felipe Poveda 
    void mostrar() const {
        Nodo<T>* actual = cabeza;
        //cout << "Lista de valores: " << endl;
        while (actual != nullptr) {
            cout << actual->getValor();
            actual = actual->getSiguiente();
        }
        cout << " nullptr" << endl;
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
                if (nodoA->getValor().getReseñas() > nodoB->getValor().getReseñas()) {
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
            Nodo<T>* actual = get(i) -> getValor();
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
    // Funcion separar o dividr para merge y mergeSort
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
    
        if (left->getValor().getReseñas() > right->getValor().getReseñas()) {
            std::swap(left, right); // Asegurar que left siempre tenga el menor valor
        }
    
        Nodo<T>* cabeza = left; // El inicio siempre es el menor
    
        while (left->getSiguiente() && right) { // Mientras haya nodos en ambas listas
            if (left->getSiguiente()->getValor().getReseñas() > right->getValor().getReseñas()) {
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
    
    void busquedaBinariaRango(int peliculaMinimo, int peliculaMaximo) {
        if (peliculaMinimo > peliculaMaximo || size == 0) {
            cout << "Rango invalido." << endl;
            return;
        }
    
        int inicio = 0, fin = size - 1;
        ListaEnlazada<T> encontrados;    
        while (inicio <= fin) {
            int medio  = inicio + (fin - inicio) / 2;
            Nodo<T>* nodoMedio = get(medio);
            int peliculaMedio  = nodoMedio->getValor().getPuntuacion();
    
            if (peliculaMedio  >= peliculaMinimo && peliculaMedio  <= peliculaMaximo) {
                int left = medio ;
                while (left >= 0 && get(left)->getValor().getPuntuacion() >= peliculaMinimo) {
                    encontrados.insertar(get(left)->getValor());
                    left--;
                }
    
                int right = medio  + 1;
                while (right < size && get(right)->getValor().getPuntuacion() <= peliculaMaximo) {
                    encontrados.insertar(get(right)->getValor());
                    right++;
                }
                break;
            }
    
            if (peliculaMedio  < peliculaMinimo) {
                inicio = medio  + 1;
            } else {
                fin = medio  - 1;
            }
        }
        cout << "_________________________________________" << endl;
        cout << endl;
        cout << "Peliculas encontradas en el rango de [" << peliculaMinimo << ", " << peliculaMaximo << "]:" << endl;
        //encontrados.bubbleSort();
        encontrados.mergeSort();
        //encontrados.selectionSort();
        //encontrados.shellSort();
        //encontrados.insertionSort();
        //encontrados.quickSort(0, encontrados.get_size() - 1, true);
        cout << "_________________________________________" << endl;
        encontrados.mostrar();
    }
};


// Clase PuntuacionPelicula
class Evaluadores {
private:
    ListaEnlazada<Calificacion> tabla;
    int puntos;
    int principio;

public:
    Evaluadores(int numCalificacion, int principio){
        this->principio = principio;
        if(!numCalificacion){
            puntos = 0;
            return;
        }
        for(int i = 0; i < numCalificacion; i++){
            int grupo = rand() % 4; // Cantidad de grupos
            int reseñas = rand() % 10; // Numero de calificacion
            puntos = puntos + reseñas;
            Calificacion a (grupo, reseñas);
            tabla.insertar(a);
        }
    }  

    int getReseñas() const{
        return puntos;
    }

    int getPrincipio() const{
        return principio;
    }

    bool esVacio(){
        return !tabla.get_size();
    }

    void ordenar(){
        tabla.shellSort();
    }

    Evaluadores(){
        puntos = -1;
    }
    
    void print(){
        tabla.mostrar();
    }

    string to_string() const {
        string str;
        int tamaño = tabla.get_size();
        for (int i = 0; i < tamaño; i++) {
            str += "(" + tabla.get(i)->getValor().to_string() + ")";
            if (i != tamaño - 1) {
                str += ", ";
            }
        }
        return str;
    }

    friend std::ostream& operator<<(std::ostream& os, const Evaluadores& e) {
        return os << e.to_string();
    }

    bool operator<(const Evaluadores& e){
        return this->puntos < e.getReseñas();
    }

    bool operator>(const Evaluadores& e){
        return this->puntos > e.getReseñas();
    }

    bool operator<=(const Evaluadores& e){
        return this->puntos <= e.getReseñas();
    }

    bool operator>=(const Evaluadores& e){
        return this->puntos >= e.getReseñas();
    }

    bool operator==(const Evaluadores& e){
        return this->puntos == e.getReseñas();
    }

    bool operator!=(const Evaluadores& e){
        return this->puntos != e.getReseñas();
    }
};

class HotelHills{
private:
    ListaEnlazada<Evaluadores> evaluador;
public: 
    HotelHills(int numEvaluadores){
        int numReseñas;
        for (int i = 0; i < numEvaluadores; i++){
            if (i != 2){
                numReseñas = rand () % 3 + 10;
            }
            else{
                numReseñas = 0;
            }
            Evaluadores eva(numReseñas, i);
            evaluador.insertar(eva);
        }
        cout << "Evaluador (grupo, calificacion) ordenado por grupo:" << endl;
        mostrar();
    }

    void mostrar() {
        for (int i = 0; i < evaluador.get_size(); i++) {
            Evaluadores eva = evaluador.get(i) -> getValor(); // Accedo al valor del nodo
            cout << eva.getPrincipio() << " -> ";
            if (eva.esVacio()) {
                cout << "Lista de registros vacia." << endl;
            } else {
                cout << eva << endl;
            }
        }
    }

    void mostrarTotalReseñas() {
        cout << "\n";
        cout << "Suma de calificaciones por evaluador:" << endl;
        for (int i = 0; i < evaluador.get_size(); i++) {
            Evaluadores eva = evaluador.get(i)->getValor(); // Accede al valor del nodo
            cout << "Evaluador " << eva.getPrincipio() << " tiene " << eva.getReseñas() << " puntos." << endl;
        }
    }

    void mostrarTotalOrdenado() {
        cout << "\n";
        evaluador.mergeSort();
        cout << "Resultado de puntos por evaluador ordenados de menor a mayor:" << endl;
        for (int i = 0; i < evaluador.get_size(); i++) {
            Evaluadores eva = evaluador.get(i)->getValor(); // Accede al valor del nodo
            cout << "Evaluador " << eva.getPrincipio() << " tiene " << eva.getReseñas() << " puntos." << endl;
        }
    }

    void mostrarEvaluadoresOrdenados() {
        for (int i = 0; i < evaluador.get_size(); i++) {
            evaluador.get(i)->getValor(); 
            evaluador.mergeSort();
        }
        cout << "\nEvaluador (grupo, calificacion) ordenado por calificacion:" << endl;
        mostrar();
    }
};

int main(){

    cout << "=============================================================" << endl;
    cout << "  Bienvenido al Sistema de Evaluación de Hill Hotels" << endl;
    cout << "=============================================================" << endl;
    cout << "Esta aplicación permite gestionar las calificaciones" << endl;
    cout << "de nuestros hoteles por parte de un grupo de evaluadores." << endl;
    cout << "Cada evaluador asigna notas del 0 al 9 a los cuatro grupos" << endl;
    cout << "de hoteles, ayudando a mantener altos estándares de calidad." << endl;
    cout << "\t¡Gracias por confiar en Hill Hotels!" << endl;
    cout << "-------------------------------------------------------------" << endl;

    int numEvaluadores;
    cout << "Numero de evaluadores? (minimo 3, maximo 6): ";
    cin >> numEvaluadores;
    if(numEvaluadores > 6 || numEvaluadores < 3){
        cout << "Numero invalido, seleccione un numero entre 3 y 6" << endl;
        main();
        return 0;
    }
    HotelHills Hs(numEvaluadores);
    Hs.mostrarTotalReseñas();
    Hs.mostrarTotalOrdenado();
    Hs.mostrarEvaluadoresOrdenados();
}
