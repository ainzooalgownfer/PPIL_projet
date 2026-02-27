/**
 * @file Groupe.h
 * @brief Implémentation du pattern Composite pour la gestion de formes composées.
 */

#ifndef GROUPE_H
#define GROUPE_H

#include "Forme.h"
#include "VisiteurForme.h"
#include <vector>
#include <string>

using namespace std;

/**
 * @class Groupe
 * @brief Représente une forme géométrique composée d'une ou plusieurs formes[cite: 13].
 * * Cette classe permet de manipuler un ensemble de formes comme une entité unique.
 */
class Groupe : public Forme {
private:
    /**
     * @brief Liste des formes constituant le groupe (simples ou composées)[cite: 13].
     * * Une forme ne peut appartenir qu'à un seul groupe à la fois[cite: 14, 75].
     */
    vector<Forme*> _formes;

public:
    /**
     * @brief Constructeur de Groupe.
     * @param couleur La couleur appliquée aux pièces constituant le groupe lors du dessin[cite: 57].
     */
    Groupe(const string& couleur) : Forme(couleur) {}

    /**
     * @brief Destructeur de Groupe.
     * * Assure la libération de la mémoire dynamique pour toutes les formes contenues.
     */
    virtual ~Groupe() {
        for (Forme* f : _formes) {
            delete f; // Libère chaque forme du groupe
        }
        _formes.clear();
    }

    /**
     * @brief Ajoute une forme à la collection du groupe.
     * @param f Pointeur vers la forme à ajouter.
     */
    void ajouter(Forme* f) {
        if (f) _formes.push_back(f);
    }

    /**
     * @brief Applique une translation à toutes les pièces constituant le groupe.
     * @param v Vecteur de translation[cite: 18].
     */
    void translation(const Vecteur2D& v) override {
        for (Forme* f : _formes) f->translation(v);
    }

    /**
     * @brief Applique une homothétie à toutes les pièces constituant le groupe.
     * @param centre Point invariant de l'opération[cite: 19].
     * @param rapport Facteur de zoom[cite: 19, 20].
     */
    void homothetie(const Vecteur2D& centre, double rapport) override {
        for (Forme* f : _formes) f->homothetie(centre, rapport);
    }

    /**
     * @brief Applique une rotation à toutes les pièces constituant le groupe.
     * @param centre Point invariant (centre de la rotation)[cite: 22].
     * @param angle Angle signé en radians[cite: 22].
     */
    void rotation(const Vecteur2D& centre, double angle) override {
        for (Forme* f : _formes) f->rotation(centre, angle);
    }

    /**
     * @brief Calcule l'aire totale du groupe.
     * * L'aire d'un groupe est la somme des aires des formes qui le composent[cite: 69].
     * @return L'aire cumulée des formes disjointes[cite: 69].
     */
    double calculerAire() const override {
        double total = 0;
        for (const Forme* f : _formes) total += f->calculerAire();
        return total;
    }

    /**
     * @brief Mise en œuvre du Design Pattern Visitor pour le dessin ou la sauvegarde[cite: 49, 65].
     * @param v Pointeur vers le visiteur (ex: TCP/IP ou Fichier)[cite: 35, 62].
     */
    void accepte(VisiteurForme* v) const override {
        v->visite(*this);
    }

    /**
     * @brief Accesseur pour la liste des formes (utile pour l'exportation via Visiteur).
     */
    const vector<Forme*>& getFormes() const { return _formes; }

    /**
     * @brief Opérateur de conversion en string pour l'affichage console[cite: 71, 93].
     * @return Une chaîne représentant la structure du groupe.
     */
    operator string() const override {
        string s = "Groupe " + _couleur + " { ";
        for (const auto& f : _formes) s += (string)(*f) + " ; ";
        s += "}";
        return s;
    }
};

#endif