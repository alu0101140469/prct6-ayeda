/**
 * @author Daniel Palenzuela Álvarez alu0101140469
 * @file abb.h
 * @brief Definición del árbol binario de búsqueda.
 */

#ifndef ABB_H
#define ABB_H

#include "ab.h"

/**
 * @brief Árbol binario de búsqueda.
 * @tparam Key Tipo de dato almacenado en el árbol.
 */
template <typename Key>
class ABB : public AB<Key> {
 public:
  /**
   * @brief Inserta una clave en el árbol.
   * @param k Clave a insertar.
   * @return true si la inserción se realiza.
   */
  bool insertar(const Key& k) override;

  /**
   * @brief Busca una clave en el árbol.
   * @param k Clave a buscar.
   * @return true si la clave está almacenada en el árbol.
   */
  bool buscar(const Key& k) const override;

 private:
  /**
   * @brief Inserta recursivamente en un subárbol.
   * @param node Raíz del subárbol.
   * @param k Clave a insertar.
   * @return true si la inserción se realiza.
   */
  bool insertarRec(NodoB<Key>*& node, const Key& k);

  /**
   * @brief Busca recursivamente una clave en un subárbol.
   * @param node Raíz del subárbol.
   * @param k Clave a buscar.
   * @return true si la clave está almacenada.
   */
  bool buscarRec(const NodoB<Key>* node, const Key& k) const;
};

// Instanciación explícita para nif para evitar problemas de enlazado.
extern template class ABB<nif>;

#endif