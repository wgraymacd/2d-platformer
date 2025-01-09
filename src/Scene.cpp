#include "Scene.hpp"
#include "GameEngine.hpp"

#include <string>
#include <map>

/// @brief constructs a new Scene object
/// @param game a reference to the game's main engine; required by derived classes of Scene to access top-level methods for Scene changing, adding, game quiting, etc.
Scene::Scene(GameEngine &game)
    : m_game(game) {}

/// @brief maps an input to an action name
/// @param input a key or mouse button
/// @param actionName the name of the action (e.g., "SHOOT")
/// @param isMouseButton boolean representing whether the input is a key or a mouse button
void Scene::registerAction(int input, const std::string &actionName, bool isMouseButton)
{
    m_actionMap[input + isMouseButton * sf::Keyboard::KeyCount] = actionName; // add constant offset to distinguish mouse clicks and keyboard clicks
}

const std::map<int, std::string> &Scene::getActionMap() const
{
    return m_actionMap;
}

/// @brief pauses the scene
/// @param paused true to pause, false to play
void Scene::setPaused(bool paused)
{
    m_paused = !m_paused;
}
