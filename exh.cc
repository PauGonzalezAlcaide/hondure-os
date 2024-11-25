#include <iostream>
#include <fstream>    //Proporciona herramientas para trabajar con archivos (escribir, leer...).
#include <assert.h>   //Pues define asserts
#include <map>        //Un contenedor asociativo que almacena pares clave-valor
                      //Las claves son únicas y se mantienen ordenadas automáticamente
#include <vector>

using namespace std;

typedef pair<int, int> P;      //rectangulo de p x q
typedef map<P, int>    M;      //numero rectangulos de ese tamaño
typedef vector<P>      VP;     //vector de rectangulos p x q
typedef pair<P, P>     PP;     //coords top left y bottom right
typedef vector<PP>     VPP;    //la solucion
typedef vector<VPP>    VVPP;   //tablero

const PP UNDEF({-1, -1}, {-1, -1});

ifstream in;
int  W, N, L;
M    contador;
VP   tipos_rect;
VPP  sol;
VVPP board;

void exh(int idx) {
    if (idx == N) {
        //encontrao chavalín
    }

    else {
        for (const P & rectangle : tipos_rect) {
            if (contador[rectangle] > 0) { //si quedan triangulos de ese tipo por poner
                --contador[rectangle];
                exh(idx + 1);  //una sin girar el rectangulo
                exh(idx + 1);  //otra girando el rectangulo
                ++contador[rectangle];
            }
        }
    }
}


void ordenalo(VP& og)

/*
Donat el nom d'un joc de proves... (lee la W, num de rectangulos de una forma p x q.)
*/
void read_instance(const char* file) {
  ifstream in(file);
  int k;
  in >> W >> N;
  k = N;
  int ni, pi, qi;
  while (k != 0) {
    in >> ni >> pi >> qi;
    k -= ni;
    contador[{pi, qi}] = ni;
    tipos_rect.push_back({pi, qi});
  }
}


int main(int argc, char** argv) {

    assert(argc == 3);

    read_instance(argv[1]);
    exh(0);
    //ofstream out(argv[2]);
    //out << "Albert" << endl;
    //out.close()
}

//exh.exe instances\small\3_2.inp salida.txt