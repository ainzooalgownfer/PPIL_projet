#ifndef VISITEUR_FORME_H
#define VISITEUR_FORME_H

// Forward declarations: telling the compiler these classes exist
class Cercle;
class Segment;
class Polygone;
class Groupe;

/**
 * Interface abstraite pour le Design Pattern Visitor.
 * Permet de séparer les opérations (dessin, sauvegarde) de la structure des formes.
 */
class VisiteurForme {
public:
    virtual ~VisiteurForme() {}
    virtual void visite(const Cercle& cercle) = 0;
    virtual void visite(const Segment& segment) = 0;
    virtual void visite(const Polygone& polygone) = 0;
    virtual void visite(const Groupe& groupe) = 0;
};

#endif