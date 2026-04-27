/**
 * @author Daniel Palenzuela Álvarez alu0101140469
 * @file ab.cc
 * @brief Implementación del TDA árbol binario abstracto.
 */

#include "ab.h"

#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

#include "nif.h"

/**
 * @brief Constructor por defecto.
 */
template <typename Key>
AB<Key>::AB() : raiz_(nullptr) {}

/**
 * @brief Destructor virtual.
 */
template <typename Key>
AB<Key>::~AB() {
  clear(raiz_);
  raiz_ = nullptr;
}

/**
 * @brief Libera recursivamente todos los nodos de un subárbol.
 * @param node Raíz del subárbol a liberar.
 */
template <typename Key>
void AB<Key>::clear(NodoB<Key>* node) {
  if (node != nullptr) {
    clear(node->izdo());
    clear(node->dcho());
    delete node;
  }
}

/**
 * @brief Recorrido inorden del árbol.
 */
template <typename Key>
void AB<Key>::inorden() const {
  inordenRec(raiz_);
  std::cout << '\n';
}

/**
 * @brief Recorrido inorden recursivo.
 * @param node Nodo raíz del subárbol actual.
 */
template <typename Key>
void AB<Key>::inordenRec(const NodoB<Key>* node) const {
  if (node != nullptr) {
    inordenRec(node->izdo());
    std::cout << node->dato() << ' ';
    inordenRec(node->dcho());
  }
}


/**
MODFI
 * @brief Suma los valores pares almacenados en el árbol.
 */
template <typename Key>
long AB<Key>::SumaPares() const {
  return SumaParesRec(raiz_);
}

/**
MODIF
 * @brief Suma recursivamente los valores pares de un subárbol.
 */
template <typename Key>
long AB<Key>::SumaParesRec(const NodoB<Key>* node) const {
  if (node == nullptr) {
    return 0;
  }

  const long value = static_cast<long>(node->dato());
  const long suma_izq = SumaParesRec(node->izdo());
  const long suma_der = SumaParesRec(node->dcho());

  if ((value % 2) == 0) {
    return value + suma_izq + suma_der;
  }
  return suma_izq + suma_der;
}


/**
 * @brief Operador de salida para imprimir el árbol.
 * @param os Flujo de salida.
 * @param tree Árbol a imprimir.
 * @return Referencia al flujo de salida.
 */
template <typename Key>
std::ostream& operator<<(std::ostream& os, const AB<Key>& tree) {
  std::vector<const NodoB<Key>*> current{tree.raiz_};
  std::size_t level = 0;

  while (!current.empty()) {
    os << "Nivel " << level << ": ";

    // Para evitar imprimir niveles completamente vacíos al final.
    bool anyNonNull = false;
    std::vector<const NodoB<Key>*> next;
    next.reserve(current.size() * 2);

    // Imprime los nodos del nivel actual y prepara el siguiente.
    for (const NodoB<Key>* node : current) {
      if (node == nullptr) {
        os << "[.] ";
      } else {
        anyNonNull = true;
        os << '[' << node->dato() << "] ";
        next.push_back(node->izdo());
        next.push_back(node->dcho());
      }
    }

    os << '\n';

    if (!anyNonNull) {
      break;
    }

    current = std::move(next);
    ++level;
  }

  return os;
}

// Instanciación explícita para nif para evitar problemas de enlazado.
template class AB<nif>;
template std::ostream& operator<< <nif>(std::ostream& os, const AB<nif>& tree);