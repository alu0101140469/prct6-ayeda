/**
 * @author Daniel Palenzuela Álvarez alu0101140469
 * @file nif.h
 * @brief Definición del tipo nif utilizado como clave en los algoritmos.
 */

#ifndef NIF_H
#define NIF_H

#include <iosfwd>

/**
 * @brief Tipo que representa la parte numérica de un NIF.
 */
class nif {
 public:
  /**
   * @brief Constructor por defecto.
   * @details Inicializa el valor con un número aleatorio válido.
   */
  nif();

  /**
   * @brief Constructor a partir de un número.
   * @param number Número para inicializar el nif.
   */
  explicit nif(long number);

  /**
   * @brief Conversión implícita a long.
   * @return El número representado por el nif.
   */
  operator long() const;

  /**
   * @brief Operador de igualdad.
   * @param other Otro nif para comparar.
   * @return true si ambos nifs son iguales.
   */
  bool operator==(const nif& other) const;

  /**
   * @brief Operador de desigualdad.
   * @param other Otro nif para comparar.
   * @return true si ambos nifs son diferentes.
   */
  bool operator!=(const nif& other) const;

  /**
   * @brief Operador menor que.
   * @param other Otro nif para comparar.
   * @return true si este nif es menor que el otro.
   */
  bool operator<(const nif& other) const;

  /**
   * @brief Operador mayor que.
   * @param other Otro nif para comparar.
   * @return true si este nif es mayor que el otro.
   */
  bool operator>(const nif& other) const;

 private:
  /**
   * @brief Comprueba si un número es un nif válido para esta práctica.
   * @param number Número a validar.
   * @return true si el número es válido.
   */
  static bool isValid(long number);

  /**
   * @brief Genera un número aleatorio válido.
   * @return Número aleatorio válido.
   */
  static long randomValue();

  long number_; // Número representado por el nif.
};

/**
 * @brief Escribe un nif en un flujo de salida.
 * @param os Flujo de salida.
 * @param value Valor a escribir.
 * @return Flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const nif& value);

#endif