/**
 * @file Cercle.h
 * @brief Implémentation de la forme géométrique Cercle.
 */

#ifndef CERCLE_H
#define CERCLE_H

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "Forme.h"
#include "VisiteurForme.h"
#include <stdexcept>
#include <cmath>

 /**
  * @class Cercle
  * @brief Représente un cercle défini par un centre et un rayon.
  * * Cette classe hérite de Forme et implémente les transformations géométriques
  * ainsi que le calcul d'aire.
  */
class Cercle : public Forme {
private:
    Vecteur2D _centre; ///< Le point central du cercle.
    double _rayon;     ///< Le rayon du cercle (doit être > 0).

public:
    /**
     * @brief Constructeur de Cercle.
     * @param centre Coordonnées du centre.
     * @param rayon Valeur du rayon (doit être strictement positive ).
     * @param couleur Nom de la couleur autorisée.
     * @throw std::invalid_argument Si le rayon est inférieur ou égal à zéro.
     */
    Cercle(const Vecteur2D& centre, double rayon, const std::string& couleur)
        : Forme(couleur), _centre(centre), _rayon(rayon) {
        if (rayon <= 0) {
            throw std::invalid_argument("Le rayon doit être strictement positif (Contrainte de cohérence )");
        }
    }

    /** @brief Destructeur virtuel de Cercle. */
    virtual ~Cercle() {}

    // Accesseurs
    const Vecteur2D& getCentre() const { return _centre; }
    double getRayon() const { return _rayon; }

    /** * @brief Translation du cercle.
     * Seul le centre subit le déplacement.
     */
    void translation(const Vecteur2D& v) override {
        _centre += v;
    }

    /** * @brief Homothétie du cercle.
     * Modifie la position du centre et la taille du rayon (opération de zoom ).
     */
    void homothetie(const Vecteur2D& centre, double rapport) override {
        _centre = centre + (_centre - centre) * rapport;
        _rayon *= std::abs(rapport);
    }

    /** * @brief Rotation du cercle.
     * Applique une rotation au centre du cercle autour d'un point invariant.
     */
    void rotation(const Vecteur2D& centre, double angle) override {
        double dx = _centre.x - centre.x;
        double dy = _centre.y - centre.y;
        double x = centre.x + dx * cos(angle) - dy * sin(angle);
        double y = centre.y + dx * sin(angle) + dy * cos(angle);
        _centre = Vecteur2D(x, y);
    }

    /** * @brief Calcule l'aire du cercle (π * r²).
     * @return L'aire sous forme de nombre réel.
     */
    double calculerAire() const override {
        return M_PI * _rayon * _rayon;
    }

    /** * @brief Pattern Visitor : Accepte un visiteur pour le dessin ou la sauvegarde.
     * @param v Le visiteur (ex: TCP/IP ou Fichier ).
     */
    void accepte(VisiteurForme* v) const override {
        v->visite(*this);
    }

    /** * @brief Conversion en chaîne de caractères.
     * @return Format textuel : "Cercle [C:(x,y), R:rayon], couleur".
     */
    operator std::string() const override {
        return "Cercle [C:" + (std::string)_centre + ", R:" + std::to_string(_rayon) + "], " + _couleur;
    }
};

#endif