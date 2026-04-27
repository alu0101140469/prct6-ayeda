/**
 * @author Daniel Palenzuela Álvarez alu0101140469
 * @file nif.cc
 * @brief Implementación del tipo nif.
 */

#include "nif.h"

#include <ostream>
#include <random>

/**
 * @brief Constructor por defecto.
 * @details Inicializa el valor con un número aleatorio válido.
 */
nif::nif() : number_(randomValue()) {}

/**
 * @brief Constructor a partir de un número.
 * @param number Número para inicializar el nif.
 */
nif::nif(long number) : number_(isValid(number) ? number : randomValue()) {}

/**
 * @brief Conversión implícita a long.
 * @return El número representado por el nif.
 */
nif::operator long() const {
  return number_;
}

/**
 * @brief Operador de igualdad.
 * @param other Otro nif para comparar.
 * @return true si ambos nifs son iguales.
 */
bool nif::operator==(const nif& other) const {
  return number_ == other.number_;
}

/**
 * @brief Operador de desigualdad.
 * @param other Otro nif para comparar.
 * @return true si ambos nifs son diferentes.
 */
bool nif::operator!=(const nif& other) const {
  return !(*this == other);
}

/**
 * @brief Operador menor que.
 * @param other Otro nif para comparar.
 * @return true si este nif es menor que el otro.
 */
bool nif::operator<(const nif& other) const {
  return number_ < other.number_;
}

/**
 * @brief Operador mayor que.
 * @param other Otro nif para comparar.
 * @return true si este nif es mayor que el otro.
 */
bool nif::operator>(const nif& other) const {
  return number_ > other.number_;
}

/**
 * @brief Comprueba si un número es un nif válido para esta práctica.
 * @param number Número a validar.
 * @return true si el número es válido.
 */
bool nif::isValid(long number) {
  return number >= 10000000L && number <= 99999999L;
}

/**
 * @brief Genera un número aleatorio válido.
 * @return Número aleatorio válido.
 */
long nif::randomValue() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<long> dist(10000000L, 99999999L);
  return dist(gen);
}

/**
 * @brief Operador de salida para imprimir un nif.
 * @param os Flujo de salida.
 * @param value Nif a imprimir.
 * @return Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& os, const nif& value) {
  os << static_cast<long>(value);
  return os;
}