class Matriz{
    int **M, n;
    public:
        Matriz(int n);
        void reservarEspac();
        void liberarEspac();
        void llenarCeros();
        void mostrarMatriz();
        void agregarAristas(int n, int YotalAristas);
        void menu();
};