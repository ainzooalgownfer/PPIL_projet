/**
 * @file Segment.h
 * @brief Implémentation de la forme géométrique Segment.
 */

#ifndef SEGMENT_H
#define SEGMENT_H

#include "Forme.h"
#include "VisiteurForme.h"

 /**
  * @class Segment
  * @brief Représente un segment de droite défini par deux points.
  * Hérite de Forme et implémente les transformations pour ses deux extrémités. 
  */
class Segment : public Forme {
private:
    Vecteur2D _p1; ///< Premier point du segment.
    Vecteur2D _p2; ///< Deuxième point du segment.

public:
    /**
     * @brief Constructeur de Segment.
     * @param p1 Premier point.
     * @param p2 Deuxième point.
     * @param couleur Couleur autorisée (black, blue, red, green, yellow, cyan). 
     */
    Segment(const Vecteur2D& p1, const Vecteur2D& p2, const std::string& couleur)
        : Forme(couleur), _p1(p1), _p2(p2) {
    }

    /** @brief Destructeur virtuel.  */
    virtual ~Segment() {}

    /** @name Accesseurs
     * Utiles pour le Visiteur (dessin/sauvegarde).
     * @{
     */
    const Vecteur2D& getP1() const { return _p1; }
    const Vecteur2D& getP2() const { return _p2; }
    /** @} */

    /** * @brief Translation du segment.
     * Déplace les deux points p1 et p2 par le vecteur v. 
     */
    void translation(const Vecteur2D& v) override {
        _p1 += v;
        _p2 += v;
    }

    /** * @brief Homothétie du segment.
     * Redimensionne le segment par rapport à un centre invariant. 
     */
    void homothetie(const Vecteur2D& centre, double rapport) override {
        _p1 = centre + (_p1 - centre) * rapport;
        _p2 = centre + (_p2 - centre) * rapport;
    }

    /** * @brief Rotation du segment.
     * Fait pivoter les deux extrémités autour d'un centre donné. 
     */
    void rotation(const Vecteur2D& centre, double angle) override {
        auto rot = [&](const Vecteur2D& p) {
            double dx = p.x - centre.x;
            double dy = p.y - centre.y;
            double x = centre.x + dx * cos(angle) - dy * sin(angle);
            double y = centre.y + dx * sin(angle) + dy * cos(angle);
            return Vecteur2D(x, y);
            };
        _p1 = rot(_p1);
        _p2 = rot(_p2);
    }

    /** * @brief Calcul de l'aire du segment.
     * @return Toujours 0.0 car un segment n'a pas de surface.
     */
    double calculerAire() const override { return 0.0; }

    /** * @brief Pattern Visitor.
     * @param v Pointeur vers le visiteur (Dessin ou Sauvegarde). 
     */
    void accepte(VisiteurForme* v) const override { v->visite(*this); }

    /** * @brief Conversion en chaîne de caractères.
     * @return Format : "Segment [(x1,y1), (x2,y2)], couleur". 
     */
    operator std::string() const override {
        return "Segment [" + (std::string)_p1 + ", " + (std::string)_p2 + "], " + _couleur;
    }
};

#endif