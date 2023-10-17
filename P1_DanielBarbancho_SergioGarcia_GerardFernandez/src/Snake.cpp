#include "Snake.h"


Snake::Snake(int nBonificacions) {

    // Inicialitza la longitud actual de l'Snake amb un valor calcular
    int currentLength = 3 + nBonificacions;

    // Crear un array de posicions per a l'Snake amb la longitud calculada
    Snake::arrayPosition = new Position[currentLength];

    // Inicialitza les tres primeres posicions de l'Snake al comen�ament del joc
    for (int i = 0; i < 3; i++) {
        Snake::arrayPosition[i] = Position(0, i);
    }
}

// Destructor de la classe Snake
Snake::~Snake() {
    // Allibera la mem�ria assignada din�micament per al membre array Position
    delete[] Snake::arrayPosition;
}


bool Snake::visualitza(int fila, int columna) const
{
    // Iterar a trav�s de les posicions en array Position
    for (int i = 0; i < Snake::currentLength; i++) {
        // Comprova si la fila i la columna coincideixen amb la posici� actual
        if (Snake::arrayPosition[i].getRow() == fila && Snake::arrayPosition[i].getCol() == columna) {
                if(i == Snake::currentLength - 1)
                {
                    // Truca al m�tode "visualitza" de la posici� actual
                    Snake::arrayPosition[i].visualitza(Snake::currentDir);
                    // Retorna veritable si es va trobar una coincid�ncia
                    return true;
                }
                else
                {
                    // Truca al m�tode "visualitza" de la posici� actual
                    Snake::arrayPosition[i].visualitza();
                    // Retorna veritable si es va trobar una coincid�ncia
                    return true;
                }
        }
    }

    // Retorna fals si no s'ha trobat cap coincid�ncia
    return false;
}

bool Snake::contains(int fila, int columna)
{
    // Creem una inst�ncia de la classe Position amb les coordenades rebudes.
    Position posicio(fila, columna);

    // Recorrem la llista de posicions del serp actual.
    for (int i = 0; i < Snake::currentLength; i++) {
        // Comprovem si la posici� actual �s igual a la posici� que estem buscant.
        // Si la trobem, retornem cert (true) per indicar que el serp cont� aquesta posici�.
        if (Snake::arrayPosition[i] == &posicio) return true;
    }

    // Si arribem a aquest punt sense trobar la posici�, retornem fals (false) per indicar que no la cont�.
    return false;
}


int* Snake::movimentSerp(MyEnum::eDirection newdir, int nRow, int nCol)
{
    // Obtenim el despla�ament associat a la nova direcci�.
    int* moviment = MyEnum::movement(newdir);

    // Establim la variable 'currentDir' de la classe Snake com la nova direcci�.
    Snake::currentDir = newdir;

    // Calculem la nova posici� del "cap" de la serp.
    int novaFila = Snake::arrayPosition[Snake::currentLength -1].getRow() + moviment[0];
    int novaColumna = Snake::arrayPosition[Snake::currentLength -1].getCol() + moviment[1];

    // Comprova si la nova fila �s menor que zero i la reinicialitza a l'�ltima fila.
    if(novaFila < 0) novaFila = nRow - 1;
    // Comprova si la nova fila �s superior al nombre total de files i la reinicialitza a zero.
    if (novaFila > nRow) novaFila = 0;
    // Comprova si la nova columna �s menor que zero i la reinicialitza a l'�ltima columna.
    if (novaColumna < 0) novaColumna = nCol - 1;
    // Comprova si la nova columna �s superior al nombre total de columnes i la reinicialitza a zero.
    if (novaColumna > nCol) novaColumna = 0;

    // Incrementa la longitud actual de la serp.
    Snake::currentLength++;

    // Verifiquem si la nova posici� ja pertany a la serp.
    if (contains(novaFila, novaColumna)) Snake::currentLength = -1;

    // Actualitzem la posici� del "cap" de la serp.
    Snake::arrayPosition[Snake::currentLength -1].putData(novaFila, novaColumna);

    // Retorna la nova posici� del "cap" de la serp.
    int* nuevaPosicion = new int[2];
    nuevaPosicion[0] = novaFila;
    nuevaPosicion[1] = novaColumna;

    return nuevaPosicion; // Retorna la nova posici� del "cap" per verificar bonificacions.
}

void Snake::doesntEat()
{
    // Comprova si la longitud actual de la serp est� per sobre de zero
    if (Snake::currentLength > 0){
        // Recorre cada segment de la serp (cada element de l'array)
        for (int i = 0; i < Snake::currentLength; i++){
            // Mou cada segment a la posici� del segment seg�ent
            Snake::arrayPosition[i].putData(Snake::arrayPosition[i + 1].getRow(), Snake::arrayPosition[i + 1].getCol());
        }
    }

    // Redueix la longitud de la serp en un segment
    Snake::currentLength--;

}

bool Snake::isDead()
{
    if (Snake::currentLength <= 0) return true;  // Comprovem si la longitud actual de la serp est� a zero o menys, en aquest cas retorna cert (true), la serp est� morta.
    return false;  // Si no �s aix�, retorna fals (false), la serp encara est� viva.
}

