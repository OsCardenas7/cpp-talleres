#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <algorithm>

using namespace std;

class Azar {
  private:
    int numeros[55];
    int suma;
    int mayor;
    int menor;
    float promedio;
    float desviacion;
    float mediana;
  public:
    Azar();
    void generar();
    void verNumeros();
    int getMayor();
    int getMenor();
    float getPromedio();
    float getDesviacion();
    float getMediana();
};

Azar::Azar() {
  generar();
}

float Azar::getMediana() {
  return mediana;
}

float Azar::getDesviacion() {
  return desviacion;
}

int Azar::getMayor() {
  return mayor;
}

int Azar::getMenor() {
  return menor;
}

float Azar::getPromedio() {
  return promedio;
}

void Azar::generar() {
  suma = 0;
  mayor = 0;
  menor = 999;
  for (int i = 0; i < 50; i++) {
    numeros[i] = rand() % 500 + 1;
    mayor = max(mayor, numeros[i]);
    menor = min(menor, numeros[i]);
    suma += numeros[i];
  }
  promedio = suma / 50.0;
  // desviacion estandar
  desviacion = 0;
  for (int i = 0; i < 50; i++) {
    desviacion += pow(numeros[i] - promedio, 2);
  }
  desviacion /= 50.0;
  desviacion = sqrt(desviacion);
  // mediana
  sort(numeros, numeros + 50);
  mediana = (numeros[24] + numeros[25]) / 2.0;
}

void Azar::verNumeros() {
  for (int i = 0; i < 50; i++) {
    cout << "#" << (i + 1) << " => " << numeros[i] << "\n";
  }
}

void menu() {
  Azar azar = Azar();
  string opt;
  while (1) {
    cout << "1. Generar numeros\n";
    cout << "2. Ver los numeros\n";
    cout << "3. Ver la desviacion estandar\n";
    cout << "4. Ver la mediana\n";
    cout << "5. Ver el mayor\n";
    cout << "6. Ver el menor\n";
    cout << "7. Ver el promedio\n";
    cout << "8. Salir\n";
    cin >> opt;
    if (opt == "1") {
      azar.generar();
      cout << "Nuevos numeros generados\n";
    } else if (opt == "2") {
      cout << "El conjunto de numeros son:\n";
      azar.verNumeros();
    } else if (opt == "3") {
      cout << "La desviacion estandar es: " << azar.getDesviacion() << "\n";
    } else if (opt == "4") {
      cout << "La mediana es: " << azar.getMediana() << "\n";
    } else if (opt == "5") {
      cout << "El numero mayor es: " << azar.getMayor() << "\n";
    }else if (opt == "6") {
      cout << "El numero menor es: " << azar.getMenor() << "\n";
    } else if (opt == "7") {
      cout << "El promedio es: " << azar.getPromedio() << "\n";
    } else if (opt == "8") {
      cout << "Adios.\n";
      break;
    } else {
      cout << "Opcion incorrecta!\n";
    }
  }
}

int main() {
  menu();
  return 0;
}