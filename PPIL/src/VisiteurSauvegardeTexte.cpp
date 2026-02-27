/**
 * @file VisiteurSauvegardeTexte.cpp
 * @brief Implémentation des méthodes de sauvegarde des formes dans un fichier texte.
 */

#include "../header/VisiteurSauvegardeTexte.h"
#include "../header/Cercle.h"
#include "../header/Segement.h" // Note : Correction du nom de fichier si nécessaire
#include "../header/Polygone.h"
#include "../header/Group.h"

 /**
  * @brief Constructeur du visiteur de sauvegarde.
  * @details Initialise le nom du fichier et efface le contenu précédent pour une nouvelle session de sauvegarde.
  */
VisiteurSauvegardeTexte::VisiteurSauvegardeTexte(const std::string& nomFichier)
    : _nomFichier(nomFichier) {
    // Vide le fichier au début d'une nouvelle session de sauvegarde
    std::ofstream ofs(_nomFichier, std::ios::trunc);
    ofs.close();
}

/**
 * @brief Sauvegarde d'un cercle.
 * @details Format : Cercle;couleur;centre;rayon.
 */
void VisiteurSauvegardeTexte::visite(const Cercle& cercle) {
    std::ofstream ofs(_nomFichier, std::ios::app);
    // Format: Cercle;couleur;centre;rayon
    ofs << "Cercle;" << cercle.getCouleur() << ";"
        << (std::string)cercle.getCentre() << ";"
        << cercle.getRayon() << std::endl;
}

/**
 * @brief Sauvegarde d'un segment.
 * @details Format : Segment;couleur;p1;p2.
 */
void VisiteurSauvegardeTexte::visite(const Segment& segment) {
    std::ofstream ofs(_nomFichier, std::ios::app);
    // Format: Segment;couleur;p1;p2
    ofs << "Segment;" << segment.getCouleur() << ";"
        << (std::string)segment.getP1() << ";"
        << (std::string)segment.getP2() << std::endl;
}

/**
 * @brief Sauvegarde d'un polygone.
 * @details Format : Polygone;couleur;point1;point2;....
 * La liste des sommets est itérée pour garantir l'extensibilité du nombre de points.
 */
void VisiteurSauvegardeTexte::visite(const Polygone& polygone) {
    std::ofstream ofs(_nomFichier, std::ios::app);
    // Format: Polygone;couleur;point1;point2;...
    ofs << "Polygone;" << polygone.getCouleur();
    for (const auto& s : polygone.getSommets()) {
        ofs << ";" << (std::string)s;
    }
    ofs << std::endl;
}

/**
 * @brief Sauvegarde récursive d'un groupe.
 * @details Utilise des balises de début et de fin pour structurer les formes composées.
 * Chaque forme enfant accepte à son tour ce visiteur pour être sauvegardée.
 */
void VisiteurSauvegardeTexte::visite(const Groupe& groupe) {
    std::ofstream ofs(_nomFichier, std::ios::app);
    // Marque le début d'un groupe avec sa couleur
    ofs << "Groupe;Debut;" << groupe.getCouleur() << std::endl;
    ofs.close(); // Fermeture pour permettre aux visites enfants d'ouvrir le fichier

    // Appel récursif pour chaque forme contenue dans le groupe
    for (const Forme* f : groupe.getFormes()) {
        f->accepte(this);
    }

    // Marque la fin de la structure du groupe
    std::ofstream ofsEnd(_nomFichier, std::ios::app);
    ofsEnd << "Groupe;Fin" << std::endl;
}