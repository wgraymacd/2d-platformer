#pragma once

#include "Components.hpp"
#include "EntityMemoryPool.hpp"
#include <string>
#include <tuple>

class Entity
{
    unsigned long m_id;

public:
    Entity(unsigned long id) : m_id(id) { }

    /// @brief get a component of type T from this entity
    template <typename T>
    T &getComponent() const
    {
        return EntityMemoryPool::Instance().getComponent<T>(m_id);
    }
    
    /// @brief check to see if this entity has a component of type T
    template <typename T>
    const bool hasComponent() const
    {
        return EntityMemoryPool::Instance().hasComponent<T>(m_id);
    }

    /// @brief add a component of type T with argument mArgs of types TArgs to this entity
    template <typename T, typename... TArgs>
    T &addComponent(TArgs &&...mArgs)
    {
        return EntityMemoryPool::Instance().addComponent<T>(m_id, std::forward<TArgs>(mArgs)...);
    }

    const std::string tag()
    {
        return EntityMemoryPool::Instance().getTag(m_id);
    }

    /// @brief destroy this entity
    void destroy()
    {
        return EntityMemoryPool::Instance().removeEntity(m_id);
    }
};