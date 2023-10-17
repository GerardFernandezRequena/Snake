#include "Snake.h"


Snake::Snake(int nBonificacions) {

    // Inicialitza la longitud actual de l'Snake amb un valor calcular
    int currentLength = 3 + nBonificacions;

    // Crear un array de posicions per a l'Snake amb la longitud calculada
    Snake::arrayPosition = new Position[currentLength];

    // Inicialitza les tres primeres posicions de l'Snake al començament del joc
    for (int i = 0; i < 3; i++) {
        Snake::arrayPosition[i] = Position(0, i);
    }
}

// Destructor de la classe Snake
Snake::~Snake() {
    // Allibera la memòria assignada dinàmicament per al membre array Position
    delete[] Snake::arrayPosition;
}


bool Snake::visualitza(int fila, int columna) const
{
    // Iterar a través de les posicions en array Position
    for (int i = 0; i < Snake::currentLength; i++) {
        // Comprova si la fila i la columna coincideixen amb la posició actual
        if (Snake::arrayPosition[i].getRow() == fila && Snake::arrayPosition[i].getCol() == columna) {
                if(i == Snake::currentLength - 1)
                {
                    // Truca al mètode "visualitza" de la posició actual
                    Snake::arrayPosition[i].visualitza(Snake::currentDir);
                    // Retorna veritable si es va trobar una coincidència
                    return true;
                }
                else
                {
                    // Truca al mètode "visualitza" de la posició actual
                    Snake::arrayPosition[i].visualitza();
                    // Retorna veritable si es va trobar una coincidència
                    return true;
                }
        }
    }

    // Retorna fals si no s'ha trobat cap coincidència
    return false;
}

bool Snake::contains(int fila, int columna)
{
    // Creem una instància de la classe Position amb les coordenades rebudes.
    Position posicio(fila, columna);

    // Recorrem la llista de posicions del serp actual.
    for (int i = 0; i < Snake::currentLength; i++) {
        // Comprovem si la posició actual és igual a la posició que estem buscant.
        // Si la trobem, retornem cert (true) per indicar que el serp conté aquesta posició.
        if (Snake::arrayPosition[i] == &posicio) return true;
    }

    // Si arribem a aquest punt sense trobar la posició, retornem fals (false) per indicar que no la conté.
    return false;
}


int* Snake::movimentSerp(MyEnum::eDirection newdir, int nRow, int nCol)
{
    // Obtenim el desplaçament associat a la nova direcció.
    int* moviment = MyEnum::movement(newdir);

    // Establim la variable 'currentDir' de la classe Snake com la nova direcció.
    Snake::currentDir = newdir;

    // Calculem la nova posició del "cap" de la serp.
    int novaFila = Snake::arrayPosition[Snake::currentLength -1].getRow() + moviment[0];
    int novaColumna = Snake::arrayPosition[Snake::currentLength -1].getCol() + moviment[1];

    // Comprova si la nova fila és menor que zero i la reinicialitza a l'última fila.
    if(novaFila < 0) novaFila = nRow - 1;
    // Comprova si la nova fila és superior al nombre total de files i la reinicialitza a zero.
    if (novaFila > nRow) novaFila = 0;
    // Comprova si la nova columna és menor que zero i la reinicialitza a l'última columna.
    if (novaColumna < 0) novaColumna = nCol - 1;
    // Comprova si la nova columna és superior al nombre total de columnes i la reinicialitza a zero.
    if (novaColumna > nCol) novaColumna = 0;

    // Incrementa la longitud actual de la serp.
    Snake::currentLength++;

    // Verifiquem si la nova posició ja pertany a la serp.
    if (contains(novaFila, novaColumna)) Snake::currentLength = -1;

    // Actualitzem la posició del "cap" de la serp.
    Snake::arrayPosition[Snake::currentLength -1].putData(novaFila, novaColumna);

    // Retorna la nova posició del "cap" de la serp.
    int* nuevaPosicion = new int[2];
    nuevaPosicion[0] = novaFila;
    nuevaPosicion[1] = novaColumna;

    return nuevaPosicion; // Retorna la nova posició del "cap" per verificar bonificacions.
}

void Snake::doesntEat()
{
    // Comprova si la longitud actual de la serp està per sobre de zero
    if (Snake::currentLength > 0){
        // Recorre cada segment de la serp (cada element de l'array)
        for (int i = 0; i < Snake::currentLength; i++){
            // Mou cada segment a la posició del segment següent
            Snake::arrayPosition[i].putData(Snake::arrayPosition[i + 1].getRow(), Snake::arrayPosition[i + 1].getCol());
        }
    }

    // Redueix la longitud de la serp en un segment
    Snake::currentLength--;

}

bool Snake::isDead()
{
    if (Snake::currentLength <= 0) return true;  // Comprovem si la longitud actual de la serp està a zero o menys, en aquest cas retorna cert (true), la serp està morta.
    return false;  // Si no és així, retorna fals (false), la serp encara està viva.
}

