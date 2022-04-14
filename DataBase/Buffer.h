namespace Data::UniBase
{
    class Buffer
    {
        
        public: static auto fill_buff(const std::string& filename) -> void
        {
            std::ofstream Buff ("buffer", std::ios::trunc);
            std::ifstream File(filename, std::ios::in);
            std::string str {};
            std::vector<std::string> vec{};
            while(getline(File, str))
            {
                vec.push_back(str);
            }
            File.close();
            for (int i{}; i<std::size(vec); i++)
                Buff<<vec[i]<<'\n';
            Buff.close();
        }
        
        public: Buffer() = default;
        public: ~Buffer() = default;
    };
}