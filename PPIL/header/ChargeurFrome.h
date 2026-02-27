/**
 * @file ChargeurForme.h
 * @brief Classe de base pour le pattern Chain of Responsibility (CoR).
 */

#ifndef CHARGEUR_FORME_H
#define CHARGEUR_FORME_H

#include <string>
#include "Forme.h"

 /**
  * @class ChargeurForme
  * @brief Maillon de la chaîne de responsabilité pour le chargement des formes.
  * * Cette classe permet de reconstituer une forme à partir d'une ligne de texte.
  * Si un maillon ne reconnaît pas le format, il passe la main au suivant.
  */
class ChargeurForme {
protected:
    ChargeurForme* _suivant; ///< Pointeur vers le maillon suivant dans la chaîne.

public:
    /**
     * @brief Constructeur du maillon.
     * @param suivant Prochain chargeur dans la hiérarchie.
     */
    ChargeurForme(ChargeurForme* suivant) : _suivant(suivant) {}

    /**
     * @brief Destructeur virtuel.
     * @details Assure la suppression récursive de toute la chaîne pour éviter les fuites mémoire.
     */
    virtual ~ChargeurForme() {
        delete _suivant;
    }

    /**
     * @brief Tente d'analyser une ligne de texte pour créer une Forme.
     * @details Si le format est reconnu, la forme est créée. Sinon, la requête est transmise au maillon suivant.
     * @param ligne La chaîne de caractères lue depuis le fichier disque (format texte).
     * @return Forme* Un pointeur vers la forme créée, ou nullptr si la fin de la chaîne est atteinte sans succès.
     */
    virtual Forme* charger(const std::string& ligne) = 0;
};

#endif