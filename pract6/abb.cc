/**
 * @author Daniel Palenzuela Álvarez alu0101140469
 * @file abb.cc
 * @brief Implementación del árbol binario de búsqueda.
 */

#include "abb.h"

#include "nif.h"

/**
 * @brief Inserta una clave en el árbol.
 * @param k Clave a insertar.
 * @return true si la inserción se realiza.
 */
template <typename Key>
bool ABB<Key>::insertar(const Key& k) {
  return insertarRec(this->raiz_, k);
}

/**
 * @brief Busca una clave en el árbol.
 * @param k Clave a buscar.
 * @return true si la clave está almacenada en el árbol.
 */
template <typename Key>
bool ABB<Key>::buscar(const Key& k) const {
  return buscarRec(this->raiz_, k);
}

/**
 * @brief Inserta recursivamente en un subárbol.
 * @param node Raíz del subárbol.
 * @param k Clave a insertar.
 * @return true si la inserción se realiza.
 */
template <typename Key>
bool ABB<Key>::insertarRec(NodoB<Key>*& node, const Key& k) {
  // Si el nodo es nulo, se inserta aquí.
  if (node == nullptr) {
    node = new NodoB<Key>(k);
    return true;
  }

  // Si la clave ya existe, no se inserta.
  if (k == node->dato()) {
    return false;
  }

  // Si la clave es menor, se inserta en el subárbol izquierdo.
  if (k < node->dato()) {
    return insertarRec(node->izdo_ref(), k);
  }
  return insertarRec(node->dcho_ref(), k);
}

/**
 * @brief Busca recursivamente una clave en un subárbol.
 * @param node Raíz del subárbol.
 * @param k Clave a buscar.
 * @return true si la clave está almacenada.
 */
template <typename Key>
bool ABB<Key>::buscarRec(const NodoB<Key>* node, const Key& k) const {
  // Si el nodo es nulo, la clave no está.
  if (node == nullptr) {
    return false;
  }

  // Si se encuentra la clave, se devuelve true.
  if (k == node->dato()) {
    return true;
  }

  // Si la clave es menor, se busca en el subárbol izquierdo.
  if (k < node->dato()) {
    return buscarRec(node->izdo(), k);
  }
  return buscarRec(node->dcho(), k);
}

// Instanciación explícita para nif para evitar problemas de enlazado.
template class ABB<nif>;