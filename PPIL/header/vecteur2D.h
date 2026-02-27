/**
 * @file Vecteur2D.h
 * @brief Classe représentant un vecteur ou un point dans un plan 2D.
 */

#ifndef VECTEUR_2D_H
#define VECTEUR_2D_H

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio> // Pour sscanf

 /**
  * @class Vecteur2D
  * @brief Gère les opérations algébriques de base pour les coordonnées 2D.
  * * Cette classe est la brique de base pour toutes les formes géométriques du projet.
  */
class Vecteur2D {
public:
    double x, y; ///< Coordonnées réelles du vecteur.

    /**
     * @brief Constructeur par défaut et d'initialisation.
     * @param x Valeur initiale de x (défaut 0).
     * @param y Valeur initiale de y (défaut 0).
     */
    explicit Vecteur2D(const double& x = 0, const double& y = 0) : x(x), y(y) {}

    /**
     * @brief Constructeur à partir d'une chaîne de caractères.
     * @details Utile pour le chargement via la Chain of Responsibility.
     * @param s Chaîne au format "(x,y)".
     */
    Vecteur2D(const char* s) {
        // Analyse la chaîne pour extraire les deux réels.
        if (sscanf(s, "(%lf,%lf)", &x, &y) != 2) {
            x = 0; y = 0; // Valeurs par défaut en cas d'erreur de format
        }
    }

    /**
     * @brief Conversion du vecteur en chaîne de caractères.
     * @return Une chaîne au format "(x,y)".
     */
    operator std::string() const {
        std::ostringstream os;
        os << "(" << x << "," << y << ")";
        return os.str();
    }

    // --- Opérations Algébriques ---

    /** @brief Addition de deux vecteurs. */
    const Vecteur2D operator+(const Vecteur2D& u) const {
        return Vecteur2D(x + u.x, y + u.y);
    }

    /** @brief Multiplication par un scalaire. */
    const Vecteur2D operator*(const double& a) const {
        return Vecteur2D(x * a, y * a);
    }

    /** @brief Addition et affectation. */
    const Vecteur2D& operator+=(const Vecteur2D& v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    /** @brief Soustraction de deux vecteurs. */
    inline const Vecteur2D operator-(const Vecteur2D& u) const {
        return *this + (-u);
    }

    /** @brief Opposé d'un vecteur (unaire). */
    const Vecteur2D operator-() const {
        return Vecteur2D(-x, -y);
    }

    /**
     * @brief Calcule le déterminant de deux vecteurs.
     * @details Crucial pour le calcul de l'aire des polygones.
     * @param v Le second vecteur.
     * @return Le résultat de (x * v.y - y * v.x).
     */
    double determinant(const Vecteur2D& v) const {
        return x * v.y - y * v.x;
    }
};

/** @brief Multiplication scalaire (format : nombre * vecteur). */
inline Vecteur2D operator*(const double a, const Vecteur2D& v) {
    return v * a;
}

/** @brief Surcharge de l'opérateur de flux pour l'affichage. */
inline std::ostream& operator<<(std::ostream& os, const Vecteur2D& u) {
    os << (std::string)u;
    return os;
}

#endif