#include <iostream>
#include <vector>
#include "header/vecteur2D.h"
#include "header/Cercle.h"
#include "header/Segement.h"
#include "header/Polygone.h"
#include "header/Group.h"
#include "header/VisiteurSauvegardeTexte.h"

int main() {
    try {
        // --- 1. SETUP GEOMETRY ---
        std::cout << "--- Test 1: Simple Shapes ---" << std::endl;
        Vecteur2D p1(0, 0), p2(2, 2);
        Segment* s1 = new Segment(p1, p2, Forme::RED);
        std::cout << (std::string)*s1 << " | Area: " << s1->calculerAire() << std::endl;

        Cercle* c1 = new Cercle(Vecteur2D(5, 5), 2.0, Forme::BLUE);
        std::cout << (std::string)*c1 << " | Area: " << c1->calculerAire() << std::endl;

        // --- 2. SETUP COMPOSITE (GROUPE) ---
        std::cout << "\n--- Test 2: Composite (Groupe) ---" << std::endl;
        Groupe* mainGroup = new Groupe(Forme::GREEN);

        // Ownership transfer: mainGroup now manages memory for these shapes
        mainGroup->ajouter(s1);
        mainGroup->ajouter(c1);
        mainGroup->ajouter(new Cercle(Vecteur2D(10, 10), 1.0, Forme::CYAN));

        std::cout << "Initial Group: " << (std::string)*mainGroup << std::endl;
        std::cout << "Total Group Area: " << mainGroup->calculerAire() << std::endl;

        // --- 3. TEST TRANSFORMATIONS ---
        std::cout << "\n--- Test 3: Transformations ---" << std::endl;

        // Translation
        Vecteur2D v(10, 10);
        mainGroup->translation(v);
        std::cout << "After Translation (10,10): " << (std::string)*mainGroup << std::endl;

        // Homothety (Zoom)
        mainGroup->homothetie(Vecteur2D(0, 0), 2.0);
        std::cout << "After Homothety (ratio 2.0): " << (std::string)*mainGroup << std::endl;

        // --- 4. TEST PERSISTENCE (VISITOR) ---
        std::cout << "\n--- Test 4: Saving to File ---" << std::endl;

       
        VisiteurSauvegardeTexte saver("sauvegarde.txt");

        
        mainGroup->accepte(&saver);

        std::cout << "Successfully saved hierarchy to 'sauvegarde.txt'." << std::endl;

        // --- 5. CLEANUP ---
        
        delete mainGroup;
        std::cout << "\n--- Cleanup Complete ---" << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "CRITICAL ERROR: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}