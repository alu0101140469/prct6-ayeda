/**
 * @author Daniel Palenzuela Álvarez alu0101140469
 * @file abe.cc
 * @brief Implementación del árbol binario equilibrado.
 */

#include "abe.h"

#include <queue>

#include "nif.h"

/**
 * @brief Inserta una clave en el árbol.
 * @param k Clave a insertar.
 * @return true si la inserción se realiza.
 */
template <typename Key>
bool ABE<Key>::insertar(const Key& k) {
  // Se inserta en el primer lugar disponible en nivel ordenado.
  if (buscar(k)) {
    return false;
  }

  // Si el árbol está vacío, se inserta la raíz.
  NodoB<Key>* nuevo = new NodoB<Key>(k);

  // Se utiliza una cola para realizar un recorrido por niveles.
  if (this->raiz_ == nullptr) {
    this->raiz_ = nuevo;
    return true;
  }

  // Recorre el árbol por niveles hasta encontrar un nodo con un hijo vacío.
  std::queue<NodoB<Key>*> cola;
  cola.push(this->raiz_);

  // Para cada nodo, se comprueba si tiene un hijo izquierdo o derecho vacío.
  while (!cola.empty()) {
    NodoB<Key>* actual = cola.front();
    cola.pop();

    // Si el hijo izquierdo está vacío, se inserta ahí.
    if (actual->izdo() == nullptr) {
      actual->set_izdo(nuevo);
      return true;
    }
    cola.push(actual->izdo());

    // Si el hijo derecho está vacío, se inserta ahí.
    if (actual->dcho() == nullptr) {
      actual->set_dcho(nuevo);
      return true;
    }
    cola.push(actual->dcho());
  }

  return false;
}

/**
 * @brief Busca una clave en el árbol.
 * @param k Clave a buscar.
 * @return true si la clave está almacenada en el árbol.
 */
template <typename Key>
bool ABE<Key>::buscar(const Key& k) const {
  return buscarRec(this->raiz_, k);
}

/**
 * @brief Busca recursivamente una clave en un subárbol.
 * @param node Raíz del subárbol.
 * @param k Clave a buscar.
 * @return true si la clave está almacenada.
 */
template <typename Key>
bool ABE<Key>::buscarRec(const NodoB<Key>* node, const Key& k) const {
  // Si el nodo es nulo, la clave no está.
  if (node == nullptr) {
    return false;
  }

  // Si se encuentra la clave, se devuelve true.
  if (node->dato() == k) {
    return true;
  }

  // Se busca en ambos subárboles, ya que el árbol no tiene orden.
  return buscarRec(node->izdo(), k) || buscarRec(node->dcho(), k);
}

// Instanciación explícita para nif para evitar problemas de enlazado.
template class ABE<nif>;