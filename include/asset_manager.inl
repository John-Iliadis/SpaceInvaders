template <typename asset_type>
std::unordered_map<std::string, std::unique_ptr<asset_type>> AssetManager<asset_type>::map;

template<typename asset_type>
const asset_type& AssetManager<asset_type>::get(const std::string &key)
{
    return get_impl(key);
}

template<typename asset_type>
void AssetManager<asset_type>::load(const std::string &key, const std::string &file_name)
{
    load_impl(key, file_name);
}

template<typename asset_type>
void AssetManager<asset_type>::load_directory(const std::string &dir)
{
    load_directory_impl(dir);
}

template<typename asset_type>
void AssetManager<asset_type>::remove(const std::string &key)
{
    remove_impl(key);
}

template<typename asset_type>
const asset_type& AssetManager<asset_type>::get_impl(const std::string &key)
{
    if (auto it = map.find(key);
            it != map.end())
    {
        return *(it->second);
    }
    else
    {
        throw std::runtime_error("AssetManager::get - Asset " + key +  " missing from map\n");
    }
}

template<typename asset_type>
void AssetManager<asset_type>::load_impl(const std::string &key, const std::string &file_name)
{
    std::unique_ptr<asset_type> asset = std::make_unique<asset_type>();

    if (!asset->loadFromFile(file_name))
    {
        throw std::runtime_error("AssetManager::load - Failed to load" + file_name + '\n');
    }

    auto result = map.insert(std::make_pair(key, std::move(asset)));

    if (!result.second)
    {
        throw std::runtime_error("AssetManager::load - Failed to insert " + file_name + " to map\n");
    }
}

template<typename asset_type>
void AssetManager<asset_type>::load_directory_impl(const std::string &dir)
{
    for (const auto& entry : fs::directory_iterator(dir))
    {
        if (fs::is_directory(entry))
        {
            load_directory_impl(entry.path().string());
        }
        else if (fs::is_regular_file(entry))
        {
            if (entry.path().extension().string() == ".txt") continue;

            std::string key = entry.path().stem().string();
            std::string file_path = entry.path().string();

            load_impl(key, file_path);
        }
    }
}

template<typename asset_type>
void AssetManager<asset_type>::remove_impl(const std::string &key)
{
    auto result = map.erase(key);

    assert(result == 1);
}
