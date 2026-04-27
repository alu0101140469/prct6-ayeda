/**
 * @author Daniel Palenzuela Álvarez alu0101140469
 * @file ab.h
 * @brief Definición del TDA árbol binario abstracto.
 */

#ifndef AB_H
#define AB_H

#include <iosfwd>

#include "nif.h"
#include "nodo_b.h"

/**
 * @brief Árbol binario abstracto.
 * @tparam Key Tipo de dato almacenado en el árbol.
 */
template <typename Key>
class AB {
 public:
  /**
   * @brief Destructor virtual.
   */
  virtual ~AB();

  /**
   * @brief Inserta una clave en el árbol.
   * @param k Clave a insertar.
   * @return true si la inserción se realiza.
   */
  virtual bool insertar(const Key& k) = 0;

  /**
   * @brief Busca una clave en el árbol.
   * @param k Clave a buscar.
   * @return true si la clave está almacenada en el árbol.
   */
  virtual bool buscar(const Key& k) const = 0;

  /**
   * @brief Recorrido inorden del árbol.
   */
  void inorden() const;

 protected:
  /**
   * @brief Constructor por defecto.
   */
  AB();

  /**
   * @brief Libera recursivamente todos los nodos de un subárbol.
   * @param node Raíz del subárbol a liberar.
   */
  void clear(NodoB<Key>* node);

  /**
   * @brief Recorrido inorden recursivo.
   * @param node Nodo raíz del subárbol actual.
   */
  void inordenRec(const NodoB<Key>* node) const;

  /**
   * @brief Raíz del árbol.
   */
  NodoB<Key>* raiz_;

  // Permite que el operador de salida acceda a los miembros protegidos.
  template <typename K>
  friend std::ostream& operator<<(std::ostream& os, const AB<K>& tree);
};

/**
 * @brief Escribe el árbol por niveles en un flujo de salida.
 * @tparam Key Tipo de dato almacenado en el árbol.
 * @param os Flujo de salida.
 * @param tree Árbol a mostrar.
 * @return Flujo de salida.
 */
template <typename Key>
std::ostream& operator<<(std::ostream& os, const AB<Key>& tree);

// Instanciación explícita para nif para evitar problemas de enlazado.
extern template class AB<nif>;
extern template std::ostream& operator<< <nif>(std::ostream& os, const AB<nif>& tree);

#endif