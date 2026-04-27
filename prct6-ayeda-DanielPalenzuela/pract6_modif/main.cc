/**
 * @author Daniel Palenzuela Álvarez alu0101140469
 * @file main.cc
 * @brief Programa principal de la práctica 6.
 */

#include <cctype>
#include <fstream>
#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <cstdlib>

#include "abe.h"
#include "abb.h"
#include "nif.h"

//modif: Crear un metodo TestUnitario() para hacer un test unitario, se debe crear un arbol manualmente, 
// metodo que sume los pares del arbol y se lanza, comprobar que la suma coincide haciendolo a papel y comprobar
// que ambos resultados coinciden (escribir antes el resultado de la suma por pantalla) y quedaria: if(totalSumaAMano==MetodoSuma() // assert
// con el metodo, si coincide imprime que coincide y si no, salta error.
// La comparacion se hace en TestUnitario()

/**
 * @brief Alias del tipo árbol utilizado en el programa.
 */
using Tree = AB<nif>;

/**
 * @brief Muestra como se ejecuta el programa.
 */
void usage() {
  std::cout << "Ejecutar: ./tdatree -ab <abe|abb> -init <manual|random|file> [s] [f]\n";
  std::cout << "-ab <abe|abb>, para indicar el tipo de árbol con el que se va a trabajar.\n";
  std::cout << "-init <manual|random|file> [s][f], indica la forma de introducir los datos de la secuencia.\n";
  std::cout << "[s], s es el número de elementos a generar\n";
  std::cout << "[f], f es el nombre del fichero de entrada\n";
  std::cout << "Ejemplo 1: ./tdatree -ab abb -init manual\n";
  std::cout << "Ejemplo 2: ./tdatree -ab abb -init random 10\n";
  std::cout << "Ejemplo 3: ./tdatree -ab abe -init file 15 data.txt\n";
}

/**
 * @brief Convierte una cadena a minúsculas.
 * @param text Cadena de entrada.
 * @return Cadena en minúsculas.
 */
std::string toLower(std::string text) {
  for (char& c : text) {
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
  }
  return text;
}

/**
 * @brief Comprueba si una cadena representa un entero no negativo.
 * @param text Cadena a comprobar.
 * @return true si es un entero no negativo.
 */
bool isUnsignedNumber(const std::string& text) {
  if (text.empty()) {
    return false;
  }

  for (char c : text) {
    if (!std::isdigit(static_cast<unsigned char>(c))) {
      return false;
    }
  }

  return true;
}

/**
 * @brief Lee un long por teclado.
 * @param prompt Mensaje a mostrar.
 * @return Valor leído.
 */
long readLong(const std::string& prompt) {
  long value;
  while (true) {
    std::cout << prompt;
    if (std::cin >> value) {
      return value;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Entrada no válida. Inténtelo de nuevo.\n";
  }
}

/**
 * @brief Inicializa el árbol con valores aleatorios.
 * @param tree Árbol destino.
 * @param count Número de claves a generar.
 */
void initRandom(Tree& tree, unsigned count) {
  for (unsigned i = 0; i < count; ++i) {
    tree.insertar(nif());
  }
}

/**
 * @brief Inicializa el árbol leyendo valores de un fichero.
 * @param tree Árbol destino.
 * @param count Número máximo de claves a leer. Si es 0, se leen todas.
 * @param filename Fichero de entrada.
 */
void initFile(Tree& tree, unsigned count, const std::string& filename) {
  std::ifstream file(filename);
  if (!file) {
    std::cerr << "No se ha podido abrir el fichero: " << filename << '\n';
    return;
  }

  long value;
  unsigned read = 0;
  while (file >> value) {
    tree.insertar(nif(value));
    ++read;
    if (count != 0U && read >= count) {
      break;
    }
  }
}

/**
 * @brief Muestra el menú interactivo.
 * @param tree Árbol a gestionar.
 */
void menu(Tree& tree) {
  int option = -1;
  while (option != 0) { // Mostrar opciones hasta que el usuario decida salir
    std::cout << "\n[0] Salir\n[1] Insertar clave\n[2] Buscar clave\n[3] Mostrar árbol inorden\nOpción: ";
    if (!(std::cin >> option)) { // Entrada no válida
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    if (option == 1) { // Insertar clave
      const long value = readLong("Clave a insertar: ");
      const bool inserted = tree.insertar(nif(value));
      std::cout << (inserted ? "Insertada correctamente.\n" : "La clave ya existe.\n");
      std::cout << tree;
    } else if (option == 2) { // Buscar clave
      const long value = readLong("Clave a buscar: ");
      const bool found = tree.buscar(nif(value));
      std::cout << (found ? "La clave está en el árbol.\n" : "La clave no está en el árbol.\n");
    } else if (option == 3) { // Mostrar árbol inorden
      tree.inorden();
    } else if (option != 0) { // Opción no válida
      std::cout << "Opción no válida.\n";
    }
  }
}

// MODIF
void TestUnitario() {
  // Crear un árbol manualmente
  ABB<nif> tree;

  // Insertar valores manualmente
  tree.insertar(nif(8));
  tree.insertar(nif(3));
  tree.insertar(nif(10));
  tree.insertar(nif(1));
  tree.insertar(nif(6));
  tree.insertar(nif(14));
  tree.insertar(nif(4));
  tree.insertar(nif(7));
  tree.insertar(nif(13));

  // Suma manual a mano
  long totalSumaAMano;
  std::cout << "TestUnitario: Introduce la suma de los pares: ";
  std::cin >> totalSumaAMano;

  // Calcular la suma con el método del árbol
  const long totalMetodo = tree.SumaPares();

  // Mostrar ambos resultados
  std::cout << "TestUnitario: Suma (a mano) = " << totalSumaAMano << '\n';
  std::cout << "TestUnitario: Suma (método SumaPares) = " << totalMetodo << '\n';

  // assert
  if (totalSumaAMano == totalMetodo) {
    std::cout << "TestUnitario: Suma coincide\n";
  } else {
    std::cerr << "TestUnitario ERROR: SUma no coincide\n";
    std::exit(EXIT_FAILURE);
  }
}

/**
 * @brief Función principal del programa.
 */
int main(int argc, char* argv[]) {
  // MODIF
  TestUnitario();

  // Se almacenan los parámetros de configuración del programa.
  std::string treeType;
  std::string initType = "manual";
  unsigned initCount = 0U;
  std::string initFileName;

  // Procesar argumentos de línea de comandos.
  for (int i = 1; i < argc; ++i) {
    const std::string arg = argv[i];
    if (arg == "-ab") { // Tipo de árbol
      if (i + 1 >= argc) {
        usage();
        return 1;
      }
      treeType = toLower(argv[++i]);
    } else if (arg == "-init") { // Tipo de inicialización
      if (i + 1 >= argc) {
        usage();
        return 1;
      }
      initType = toLower(argv[++i]);

      if (initType == "random") { // Si es random, se espera un número de elementos a generar.
        if (i + 1 < argc && isUnsignedNumber(argv[i + 1])) {
          initCount = static_cast<unsigned>(std::stoul(argv[++i]));
        }
      } else if (initType == "file") { // Si es file, se espera un número máximo de elementos a leer y un nombre de fichero.
        if (i + 1 < argc && isUnsignedNumber(argv[i + 1])) {
          initCount = static_cast<unsigned>(std::stoul(argv[++i]));
        }
        if (i + 1 < argc && argv[i + 1][0] != '-') {
          initFileName = argv[++i];
        }
      }
    }
  }

  // Validar que se ha especificado un tipo de árbol.
  if (treeType.empty()) {
    usage();
    return 1;
  }

  // Crear el árbol según el tipo especificado.
  std::unique_ptr<Tree> tree;
  if (treeType == "abe") { // Árbol binario equilibrado
    tree = std::make_unique<ABE<nif>>();
  } else if (treeType == "abb") { // Árbol binario de búsqueda
    tree = std::make_unique<ABB<nif>>();
  } else { // Tipo de árbol no válido
    std::cerr << "Tipo de árbol no válido: " << treeType << '\n';
    return 1;
  }

  if (initType == "manual") { // Inicialización manual, el árbol se muestra vacío.
    std::cout << "Árbol vacío\n" << *tree;
  } else if (initType == "random") { // Inicialización aleatoria, se generan initCount claves aleatorias.
    initRandom(*tree, initCount);
    std::cout << *tree;
  } else if (initType == "file") { // Inicialización desde fichero, se leen hasta initCount claves del fichero initFileName.
    if (initFileName.empty()) { // Si no se ha especificado un nombre de fichero, se muestra un error.
      std::cerr << "Falta el nombre del fichero para -init file.\n";
      return 1;
    }
    initFile(*tree, initCount, initFileName);
    std::cout << *tree;
  } else { // Tipo de inicialización no válido
    std::cerr << "Tipo de inicialización no válido: " << initType << '\n';
    return 1;
  }

  // Mostrar el menú interactivo para gestionar el árbol.
  menu(*tree);
  
  return 0;
}