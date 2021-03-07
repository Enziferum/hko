//
// Created by HP on 06.03.2021.
//

#pragma once

#include <unordered_map>
#include <memory>
#include <string>

namespace hko{

    template<typename T, typename Id = std::string>
    class ResourceManager{
    public:
        ResourceManager() = default;
        ResourceManager(const ResourceManager&)=delete;
        ResourceManager& operator=(const ResourceManager&)=delete;

        ~ResourceManager() = default;

        bool loadFile(const std::string& path, const Id& idx);
        T& get(const Id& id) const;
    private:
        std::unordered_map<Id, std::unique_ptr<T>> m_resouces;
    };

    template<typename T, typename Id>
    bool ResourceManager<T, Id>::loadFile(const std::string &path, const Id &idx) {
                std::unique_ptr<T> resource = std::make_unique<T>();

        auto found = m_resouces.find(idx);
        if(found != m_resouces.end())
            return false;

        if(!resource->loadFromFile(path))
            return false;


        m_resouces.insert(std::pair<std::string, std::unique_ptr<T>> (idx, std::move(resource)));
        return true;
    }

    template<typename T, typename Id>
    T& ResourceManager<T, Id>::get(const Id& id) const{
        return *m_resouces.at(id);
    }

}