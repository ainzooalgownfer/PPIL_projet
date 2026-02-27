🏗 Projet PPIL - Guide du développeur : J’ai mis en place l’architecture de base (classes abstraites, patron Composite et interface Visiteur). Pour finaliser le projet, suivez ces instructions.

Géométrie et mathématiques (Expert en mathématiques) : Les classes de base Vecteur2D et Forme sont prêtes. Vous devez implémenter la logique dans les classes dérivées.

Transformations : Implémentez la rotation (centre, angle) et l’homothétie (centre, rapport) dans Cercle, Segment et Polygone.

Aire : Implémentez la méthode calculerAire(). Pour Polygone, utilisez la méthode du déterminant (formule de Shoelace) de l’annexe.

Opérateurs : Utilisez les opérateurs surchargés de Vecteur2D (+, -, *) pour un code géométrique plus clair.

Réseau et dessin (Expert en réseau) : J’ai fourni la classe de base Singleton pour la connexion et l’interface Visiteur pour le dessin.

Connexion : Créez une classe héritant de ConnexionManager pour gérer le socket (Winsock/Linux).

VisiteurDessin : Créez un Visiteur concret. Chaque méthode visite() doit construire le protocole de chaîne (par exemple, "Cercle;red;10,10;5") et l'envoyer via le ConnexionManager.

Chargement (Expert en persistance) : J'ai implémenté la logique d'enregistrement. Vous devez implémenter la chaîne de responsabilité pour recharger le fichier.

Chargeurs : Héritez de ChargeurForme pour créer ChargeurCercle, ChargeurSegment, etc.

La chaîne : Si un chargeur ne reconnaît pas le préfixe de ligne, appelez _suivant->charger(ligne).

Groupes : Gérez les marqueurs Groupe;Debut et Groupe;Fin pour reconstruire la hiérarchie imbriquée.

🚫 Règles de base : Pas de couleurs codées en dur : Utilisez Forme::RED, Forme::BLUE, etc.

Mémoire : La classe Groupe libère la mémoire de ses enfants dans son destructeur. Ne supprimez pas manuellement les formes ajoutées à un groupe.

Radians : Toute la logique de rotation doit utiliser les radians.
