/*********************************************************************
(c) Alex Raag 2021
https://github.com/Enziferum
hko - Zlib license.
This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:
1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.
2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

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