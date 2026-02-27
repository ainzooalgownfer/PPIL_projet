🏗 PPIL Project - Developer Guide
I've set up the core architecture (Abstract classes, Composite pattern, and Visitor interface). To finish the project, follow these instructions.

1. Geometry & Math (Mathematics Expert)
The Vecteur2D and Forme base classes are ready. You need to implement the logic in the inherited classes.

Transformations: Implement rotation(centre, angle) and homothetie(centre, rapport) in Cercle, Segment, and Polygone.

Area: Implement calculerAire(). For Polygone, use the determinant method (Shoelace formula) from the annex.

Operators: Use the overloaded operators in Vecteur2D (+, -, *) to keep the geometry code clean.

2. Networking & Drawing (Network Expert)
I’ve provided the Singleton base for the connection and the Visitor interface for drawing.

Connection: Create a class inheriting from ConnexionManager to handle the socket (Winsock/Linux).

VisiteurDessin: Create a concrete Visitor. Each visite() method should build the string protocol (e.g., "Cercle;red;10,10;5") and send it via the ConnexionManager.

3. Loading (Persistence Expert)
I implemented the saving logic. You need to implement the Chain of Responsibility to load the file back.

Loaders: Inherit from ChargeurForme to create ChargeurCercle, ChargeurSegment, etc..

The Chain: If a loader doesn't recognize the line prefix, call _suivant->charger(ligne).

Groups: Handle Groupe;Debut and Groupe;Fin markers to reconstruct the nested hierarchy.

🚫 The Ground Rules
No Hardcoded Colors: Use Forme::RED, Forme::BLUE, etc..

Memory: The Groupe class cleans up its own children in its destructor. Don't manually delete shapes that have been added to a group.

Radians: All rotation logic must use radians.
