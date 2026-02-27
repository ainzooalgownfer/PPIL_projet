/**
 * @file VisiteurSauvegardeTexte.h
 * @brief Visiteur concret pour la sauvegarde des formes au format texte.
 */

#ifndef VISITEUR_SAUVEGARDE_TEXTE_H
#define VISITEUR_SAUVEGARDE_TEXTE_H

#include "VisiteurForme.h"
#include <string>
#include <fstream>

 /**
  * @class VisiteurSauvegardeTexte
  * @brief Implémente le Design Pattern Visitor pour l'exportation sur disque.
  * * Cette classe sépare l'algorithmique de sauvegarde de la structure des formes,
  * permettant ainsi d'envisager d'autres formats (XML, BDD) sans modifier les classes Forme.
  */
class VisiteurSauvegardeTexte : public VisiteurForme {
private:
    std::string _nomFichier; ///< Nom du fichier texte de destination.

public:
    /**
     * @brief Constructeur du visiteur de sauvegarde.
     * @param nomFichier Chemin du fichier disque.
     */
    VisiteurSauvegardeTexte(const std::string& nomFichier);

    /**
     * @brief Destructeur virtuel.
     */
    virtual ~VisiteurSauvegardeTexte() {}

    /**
     * @name Méthodes de visite
     * Chaque méthode est responsable de l'écriture des données spécifiques
     * d'une forme dans le fichier texte.
     * @{
     */

     /** @brief Sauvegarde les données d'un Cercle (centre, rayon, couleur). */
    void visite(const Cercle& cercle) override;

    /** @brief Sauvegarde les données d'un Segment (points extrémités, couleur). */
    void visite(const Segment& segment) override;

    /** @brief Sauvegarde les données d'un Polygone (liste des sommets, couleur). */
    void visite(const Polygone& polygone) override;

    /** * @brief Sauvegarde un Groupe de manière récursive.
     * La couleur du groupe est appliquée à chaque pièce qui en fait partie.
     */
    void visite(const Groupe& groupe) override;
    /** @} */
};

#endif
