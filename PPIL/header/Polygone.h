/**
 * @file Polygone.h
 * @brief Implémentation de la forme géométrique Polygone (et par extension Triangle).
 */

#ifndef POLYGONE_H
#define POLYGONE_H

#include "Forme.h"
#include "VisiteurForme.h"
#include <vector>
#include <cmath>

 /**
  * @class Polygone
  * @brief Représente un polygone quelconque fermé.
  *  Gère une liste de sommets et implémente les algorithmes géométriques vectoriels.
  */
class Polygone : public Forme {
protected:
    std::vector<Vecteur2D> _sommets; ///< Liste dynamique des sommets du polygone.

public:
    /**
     * @brief Constructeur de Polygone.
     * @param sommets Vecteur contenant les points (Vecteur2D) du polygone.
     * @param couleur Couleur de la forme.
     */
    Polygone(const std::vector<Vecteur2D>& sommets, const std::string& couleur)
        : Forme(couleur), _sommets(sommets) {
    }

    /** @brief Destructeur virtuel. */
    virtual ~Polygone() {}

    /** @brief Accesseur pour la liste des sommets. */
    const std::vector<Vecteur2D>& getSommets() const { return _sommets; }

    /** * @brief Translation du polygone.
     *  Applique le vecteur de translation à chaque sommet.
     */
    void translation(const Vecteur2D& v) override {
        for (auto& s : _sommets) s += v;
    }

    /** * @brief Homothétie du polygone.
     * Modifie la position de chaque sommet par rapport au point invariant.
     */
    void homothetie(const Vecteur2D& centre, double rapport) override {
        for (auto& s : _sommets) s = centre + (s - centre) * rapport;
    }

    /** * @brief Rotation du polygone.
     *  Applique la rotation trigonométrique à chaque sommet.
     */
    void rotation(const Vecteur2D& centre, double angle) override {
        for (auto& s : _sommets) {
            double dx = s.x - centre.x;
            double dy = s.y - centre.y;
            double x = centre.x + dx * cos(angle) - dy * sin(angle);
            double y = centre.y + dx * sin(angle) + dy * cos(angle);
            s = Vecteur2D(x, y);
        }
    }

    /** * @brief Calcule l'aire du polygone.
     *  Utilise la somme des déterminants des sommets consécutifs (formule du lacet).
     * @return L'aire réelle positive du polygone.
     */
    double calculerAire() const override {
        double aire = 0;
        size_t n = _sommets.size();
        if (n < 3) return 0; // Un polygone doit avoir au moins 3 sommets

        for (size_t i = 0; i < n; ++i) {
            aire += _sommets[i].determinant(_sommets[(i + 1) % n]);
        }
        return std::abs(aire) / 2.0;
    }

    /** * @brief Pattern Visitor pour le dessin ou la sauvegarde.
     * 
     */
    void accepte(VisiteurForme* v) const override { v->visite(*this); }

    /** * @brief Conversion en chaîne de caractères.
     *  Affiche la liste des sommets et la couleur.
     */
    operator std::string() const override {
        std::string s = "Polygone [";
        for (const auto& v : _sommets) s += (std::string)v + " ";
        return s + "], " + _couleur;
    }
};

#endif