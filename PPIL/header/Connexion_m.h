/**
 * @file ConnexionManager.h
 * @brief Singleton gérant l'initialisation du réseau et la communication.
 */

#ifndef CONNEXION_MANAGER_H
#define CONNEXION_MANAGER_H

#include <string>
#include <iostream>

 /**
  * @class ConnexionManager
  * @brief Gère la connexion unique au serveur Java via le pattern Singleton.
  * * L'initialisation du réseau (ex: Winsock) doit être effectuée ici pour garantir
  * qu'elle ne soit faite qu'une seule fois[cite: 54, 55].
  */
class ConnexionManager {
private:
    static ConnexionManager* _instance; ///< L'instance unique du Singleton.

    /**
     * @brief Constructeur privé pour empêcher l'instanciation directe.
     * C'est ici que l'Expert Réseau placera l'initialisation de Winsock ou des sockets Unix.
     */
    ConnexionManager() {
        // L'initialisation de la bibliothèque réseau doit être faite ici.
    }

public:
    /**
     * @brief Récupère l'instance unique du gestionnaire de connexion.
     * @return ConnexionManager* L'unique instance du Singleton.
     */
    static ConnexionManager* getInstance() {
        if (_instance == nullptr) {
            _instance = new ConnexionManager();
        }
        return _instance;
    }

    /**
     * @brief Envoie une requête textuelle au serveur de dessin Java.
     * @details Cette méthode sera surchargée ou complétée par l'Expert Réseau
     * pour gérer l'envoi effectif via TCP/IP.
     * @param requete La chaîne de caractères formatée selon le protocole choisi.
     */
    virtual void envoyer(const std::string& requete) {
        // Implémentation temporaire pour le débogage.
        std::cout << "Envoi au serveur : " << requete << std::endl;
    }

    // Empêcher la copie et l'affectation pour préserver le Singleton.
    ConnexionManager(const ConnexionManager&) = delete;
    void operator=(const ConnexionManager&) = delete;
};

// Initialisation de l'instance statique (à placer dans ConnexionManager.cpp)
// ConnexionManager* ConnexionManager::_instance = nullptr;

#endif