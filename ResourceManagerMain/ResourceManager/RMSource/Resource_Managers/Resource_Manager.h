#ifndef RESOURCE_MANAGER_H_INCLUDED
#define RESOURCE_MANAGER_H_INCLUDED

#include <map>

template<typename Enum, typename Resource>
class Resource_Manager
{
    public:
        const Resource& get(Enum name) const
        {
            return m_resources.at(name);
        }

    protected:
        void addResource(Enum name, const std::string& fileName)
        {
            Resource res;
            res.loadFromFile(fileName);

            m_resources.insert(std::make_pair(name, res));
        }

    private:
        std::map<Enum, Resource> m_resources;

};
#endif // RESOURCE_MANAGER_H_INCLUDED
