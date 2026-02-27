/**
 * @file Forme.h
 * @brief Classe de base abstraite représentant une forme géométrique.
 */

#ifndef FORME_H
#define FORME_H

#include <string>
#include <vector>
#include "Vecteur2D.h"

 /**
  * @class VisiteurForme
  * @brief Déclaration anticipée pour le Design Pattern Visitor.
  */
class VisiteurForme;

/**
 * @class Forme
 * @brief Classe abstraite fondamentale pour toutes les formes (simples ou composées).
 * * Cette classe définit le contrat pour les transformations, le calcul d'aire,
 * et l'exportation via le pattern Visitor.
 */
class Forme {
protected:
    /** * @brief Couleur de la forme.
     * Doit être : "black", "blue", "red", "green", "yellow" ou "cyan".
     */
    std::string _couleur;

public:
    // Constantes statiques pour les couleurs autorisées 
    static const std::string BLACK;
    static const std::string BLUE;
    static const std::string RED;
    static const std::string GREEN;
    static const std::string YELLOW;
    static const std::string CYAN;

    /**
     * @brief Constructeur de Forme.
     * @param couleur La couleur initiale (par défaut "black").
     */
    Forme(const std::string& couleur = "black") : _couleur(couleur) {}

    /**
     * @brief Destructeur virtuel pur.
     * @details Crucial pour la gestion de la mémoire et la suppression correcte
     * des formes dérivées via un pointeur Forme*.
     */
    virtual ~Forme() {}

    /** @brief Retourne la couleur actuelle de la forme. */
    virtual const std::string& getCouleur() const { return _couleur; }

    /** @brief Modifie la couleur de la forme. */
    virtual void setCouleur(const std::string& c) { _couleur = c; }

    /**
     * @name Transformations Géométriques
     * @{
     */
     /** @brief Applique une translation par un vecteur. */
    virtual void translation(const Vecteur2D& vecteur) = 0;

    /** @brief Applique une homothétie par rapport à un centre et un rapport. */
    virtual void homothetie(const Vecteur2D& centre, double rapport) = 0;

    /** @brief Applique une rotation par rapport à un centre et un angle en radians. */
    virtual void rotation(const Vecteur2D& centre, double angleRadians) = 0;
    /** @} */

    /**
     * @name Calculs et Représentation
     * @{
     */
     /** @brief Calcule l'aire de la forme. */
    virtual double calculerAire() const = 0;

    /** @brief Opérateur de conversion en string pour l'affichage ou l'export. */
    virtual operator std::string() const = 0;
    /** @} */

    /**
     * @brief Design Pattern Visitor.
     * @details Permet d'ajouter des fonctionnalités (dessin, sauvegarde) sans modifier
     * les classes de formes existantes.
     * @param visiteur Pointeur vers le visiteur souhaité.
     */
    virtual void accepte(VisiteurForme* visiteur) const = 0;
};



#endif