#include <fstream>
class Matriz{
    int **M, n,nAristas;

    public:
        Matriz(int n);
        Matriz();
        void reservarEspac();
        void liberarEspac();
        void llenarCeros();
        void mostrarMatriz();
        void agregarAristas();

        void eliminarAristas();
        
        //archivo
        template <typename T>
        bool abrirFich(T& f);
        void guardarArchivo();

        //grafo
        void mostrarGrafo();
};