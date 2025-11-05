#pragma once
#include <any>
#include <string>
#include <unordered_map>


namespace std
{
	class any;
}

class BlackBoard
{
public:
    template <typename T>
    void Set(const std::string& key, const T& value)
    {
        m_data[key] = value;
    }

    template <typename T>
    T Get(const std::string& key)
    {
        return std::any_cast<T>(m_data[key]);
    }

    bool Has(const std::string& key) const
    {
        return m_data.find(key) != m_data.end();
    }

private:
    std::unordered_map<std::string, std::any> m_data;
};
