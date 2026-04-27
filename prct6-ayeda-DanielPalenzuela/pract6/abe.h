/**
 * @author Daniel Palenzuela Álvarez alu0101140469
 * @file abe.h
 * @brief Definición del árbol binario equilibrado.
 */

#ifndef ABE_H
#define ABE_H

#include "ab.h"

/**
 * @brief Árbol binario equilibrado.
 * @tparam Key Tipo de dato almacenado en el árbol.
 */
template <typename Key>
class ABE : public AB<Key> {
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
   * @brief Busca recursivamente una clave en un subárbol.
   * @param node Raíz del subárbol.
   * @param k Clave a buscar.
   * @return true si la clave está almacenada.
   */
  bool buscarRec(const NodoB<Key>* node, const Key& k) const;
};

// Instanciación explícita para nif para evitar problemas de enlazado.
extern template class ABE<nif>;

#endif