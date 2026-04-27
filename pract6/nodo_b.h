/**
 * @author Daniel Palenzuela Álvarez alu0101140469
 * @file nodo_b.h
 * @brief Definición del nodo binario genérico.
 */

#ifndef NODO_B_H
#define NODO_B_H

/**
 * @brief Nodo binario genérico.
 * @tparam Key Tipo de dato almacenado en el nodo.
 */
template <typename Key>
class NodoB {
 public:
  /**
   * @brief Constructor por defecto.
   */
  NodoB() : dato_(), izdo_(nullptr), dcho_(nullptr) {}

  /**
   * @brief Constructor con dato.
   * @param dato Dato a almacenar.
   */
  explicit NodoB(const Key& dato) : dato_(dato), izdo_(nullptr), dcho_(nullptr) {}

  /**
   * @brief Obtiene el dato del nodo.
   * @return Referencia constante al dato.
   */
  const Key& dato() const { return dato_; }

  /**
   * @brief Obtiene el hijo izquierdo.
   * @return Puntero al hijo izquierdo.
   */
  NodoB<Key>* izdo() const { return izdo_; }

  /**
   * @brief Obtiene el hijo izquierdo para modificarlo.
   * @return Referencia al puntero del hijo izquierdo.
   */
  NodoB<Key>*& izdo_ref() { return izdo_; }

  /**
   * @brief Obtiene el hijo derecho.
   * @return Puntero al hijo derecho.
   */
  NodoB<Key>* dcho() const { return dcho_; }

  /**
   * @brief Obtiene el hijo derecho para modificarlo.
   * @return Referencia al puntero del hijo derecho.
   */
  NodoB<Key>*& dcho_ref() { return dcho_; }

  /**
   * @brief Asigna el hijo izquierdo.
   * @param node Nuevo hijo izquierdo.
   */
  void set_izdo(NodoB<Key>* node) { izdo_ = node; }

  /**
   * @brief Asigna el hijo derecho.
   * @param node Nuevo hijo derecho.
   */
  void set_dcho(NodoB<Key>* node) { dcho_ = node; }

 protected:
  Key dato_; // Dato almacenado en el nodo.
  NodoB<Key>* izdo_; // Puntero al hijo izquierdo.
  NodoB<Key>* dcho_; // Puntero al hijo derecho.
};

#endif